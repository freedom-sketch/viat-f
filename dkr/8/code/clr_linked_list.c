#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "clr_linked_list.h"

static int find_tail(Node *list, int head_idx)
{
    int current = head_idx;
    while (list[current].next != head_idx) {
        current = list[current].next;
    }

    return current;
}

int push(Node *list, int *head, long long data)
{
    int new_idx = -1;
    for (int i = 0; i < SIZE; i++) {
        if (list[i].busy == false) {
            new_idx = i;
            break;
        }
    }

    if (new_idx == -1) return 1;

    list[new_idx].data = data;
    list[new_idx].busy = true;

    if (*head == -1) {
        *head = new_idx;
        list[new_idx].next = new_idx;
    } else {
        int tail = find_tail(list, *head);
        list[new_idx].next = *head;
        list[tail].next = new_idx;
    }
    return 0;
}

long long pop(Node *list, int *head)
{
    if (*head == -1) {
        return LLONG_MAX;
    }

    int head_idx = *head;
    long long data = list[head_idx].data;
    int tail = find_tail(list, head_idx);

    if (tail == head_idx) {
        list[head_idx].busy = false;
        *head = -1;
    } else {
        *head = list[head_idx].next;
        list[tail].next = *head;
        list[head_idx].busy = false;
    }

    return data;
}

void print_list(Node *list, int head_idx)
{
    if (head_idx == -1) {
        printf("Список пуст\n");
        return;
    }

    int current = head_idx;
    printf("[ ");
    do {
        printf("%lld ", list[current].data);
        current = list[current].next;
    } while (current != head_idx);
    printf("]\n");
}

void print_color(const char *str, const char *color)
{
    printf("%s%s%s", color, str, RESET);
}

void pause()
{
    printf("Нажмите Enter для выхода...");
    while (getchar() != '\n');
    getchar();
}