/* Простая утилита для проверки программы на утечки памяти. При подключении, макросами подменяет функции malloc(), free(), realloc().
При каждом вызове malloc() добавляет адрес и размер выделенной памяти в односвязный список
При вызове free() совобождает список и удаляет соответсвенный узел списка
При вызове realloc() на 0 байт работает как free(). При вызове на иные размеры меняет адрес и размер в узле списка, если до этого память не отслеживалась,
то выдает предупреждение и добавляет в список. */

#include <stdio.h>
#include <stdlib.h>
#include "memtracker.h"

#undef malloc
#undef free
#undef realloc

Block *head = NULL;

static void append(Block *new_block)
{
    if (head == NULL) {
        head = new_block;
        return;
    }

    Block *ptr = head;
    for (;ptr->next != NULL; ptr = ptr->next);

    ptr->next = new_block;
}

static Block *find_by_address(void *_addr)
{
    if (head == NULL) return NULL;

    Block *ptr = head;
    for (;ptr != NULL; ptr = ptr->next) {
        if (ptr->addr == _addr) return ptr;
    }
    return NULL;
}

static void delete(Block *block)
{
    if (block == head) {
        Block *tmp_ptr = head;
        head = head->next;
        free(tmp_ptr);
        return;
    }

    Block *ptr = head;
    for (;ptr != NULL; ptr = ptr->next) {
        if (ptr->next == block) {
            ptr->next = block->next;
            free(block);
            return;
        }
    }
}

void *mtmalloc(size_t size, const char* file, int line)
{
    void *ptr = malloc(size);
    if (ptr == NULL) return NULL;

    Block *new_block = malloc(sizeof(Block));
    if (new_block == NULL) {
        free(ptr);
        return NULL;
    }
    new_block->addr = ptr;
    new_block->size = size;
    new_block->next = NULL;
    new_block->file = file;
    new_block->line = line;

    append(new_block);
    return ptr;
}

void mtfree(void *memory)
{
    Block *block = find_by_address(memory);
    if (block == NULL) {
        fprintf(stderr, RED "address %p is not occupied\n" RESET, memory);
        return;
    }

    delete(block);
    free(memory);
}

void *mtrealloc(void *ptr, size_t size, const char* file, int line) {
    if (ptr == NULL) return mtmalloc(size, file, line);
    if (size == 0 && ptr != NULL) {
        mtfree(ptr);
        return NULL;
    }
    
    Block *old_block = find_by_address(ptr);

    void *new_ptr = realloc(ptr, size);
    
    if (new_ptr != NULL) {
        if (old_block != NULL) {
            old_block->addr = new_ptr;
            old_block->size = size;
            old_block->file = file;
            old_block->line = line;
        } else {
            fprintf(stderr, RED "WARNING: realloc untracked address %p at %s:%d\n" RESET, ptr, file, line);
            Block *new_block = malloc(sizeof(Block));
            new_block->addr = new_ptr;
            new_block->size = size;
            new_block->file = file;
            new_block->line = line;
            new_block->next = NULL;
            append(new_block);
            fprintf(stderr, "INFO: address tracking %p added\n", ptr);
        }
    }
    return new_ptr;
}

void check_leaks()
{
    if (head != NULL) {
        for (Block *ptr = head; ptr != NULL; ptr = ptr->next) {
            fprintf(stderr, RED "ERROR: leak in %s:%d! Not freed %zu bytes at address %p\n" RESET,
                ptr->file, ptr->line, ptr->size, ptr->addr);
        }
    }
}
