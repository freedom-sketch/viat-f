#ifndef CIRCULAR_SINGLY_LINKED_LIST
#define CIRCULAR_SINGLY_LINKED_LIST

#define GRN "\033[32m"
#define RED "\033[31m"
#define LBLE "\033[36m"
#define RESET "\033[0m"

#define SIZE 30

#include <stdbool.h>

typedef struct Node {
    long long data;
    bool busy;
    int next;
} Node;

int find_tail(Node *list, int head_idx);
int push(Node *list, int *head, long long data);
long long pop(Node *list, int *head);
void print_list(Node *list, int head_idx);

void print_color(const char *str, const char *color);
void pause();

#endif