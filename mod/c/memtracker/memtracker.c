#include <stdio.h>
#include <stdlib.h>

#include "memtracker.h"
#undef malloc
#undef free

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
        fprintf(stderr, RED "ERROR: address %p is not occupied\n" RESET, memory);
        return;
    }

    delete(block);
    free(memory);
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