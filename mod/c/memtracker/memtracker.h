#ifndef MEMTRACKER_H
#define MEMTRACKER_H

#define RED "\033[31m"
#define RESET "\033[0m"

#include <stdlib.h>

typedef struct Block {
    void *addr;
    size_t size;
    struct  Block *next;

    const char* file;
    int line;
} Block;

extern Block *head;

void *mtmalloc(size_t size, const char* file, int line);
void mtfree(void *memory);
void *mtrealloc(void *ptr, size_t size, const char* file, int line);

#define malloc(size) mtmalloc(size, __FILE__, __LINE__)
#define free(ptr) mtfree(ptr)
#define realloc(ptr, size) mtrealloc(ptr, size, __FILE__, __LINE__)

void __attribute__((destructor)) check_leaks();

#endif