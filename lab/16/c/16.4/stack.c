#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "stack.h"

Stack *init_stack()
{
    Stack *stack = malloc(sizeof(Stack));
    stack->tags = malloc(sizeof(int) * START_CAPACITY);
    stack->size = 0;
    stack->capacity = START_CAPACITY;

    return stack;
}

void grow_stack(Stack *s)
{
    int new_capacity = s->capacity * 2;

    int *temp = (int *)realloc(s->tags, new_capacity*sizeof(int));
    if (temp != NULL) {
        s->tags = temp;
        s->capacity = new_capacity;
    }
}

void push(Stack *s, int x)
{
    if (s->size >= s->capacity) grow_stack(s);
    s->tags[s->size++] = x;
}

int pop(Stack *s)
{
    if (s->size == 0) return -1;
    return s->tags[--s->size];
}

bool is_empty_stack(Stack *s)
{
    return s->size == 0;
}

void print_color(const char *str, const char *color)
{
    printf("%s%s%s", color, str, RESET);
}