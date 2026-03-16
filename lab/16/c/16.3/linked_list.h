#ifndef LINKED_LIST
#define LINKED_LIST

#if defined(_WIN32) || defined(_WIN64)
    #define CLEAR "cls"
    #define SET_UTF8 "chcp 65001 > nul"
#elif defined(__linux__)
    #define SET_UTF8 "echo"
    #define CLEAR "clear"
#endif

#define GRN "\033[32m"
#define RED "\033[31m"
#define LBLE "\033[36m"
#define RESET "\033[0m"
#define STR_SIZE 128

#define A 3 /* Минимальный размер слова в символах */
#define B 30 /* Максимальный размер слова в символах */

#define MIN_NUM_WRD 10
#define MAX_NUM_WRD 50

#include <stdbool.h>
#include <stdio.h>

/* Структура узла односвязного списка-словаря */
typedef struct Node {
    char *word;
    int count;
    struct Node *next;
} Node;

/* Структура узла односвязного списка чисел */
typedef struct Node_n {
    int num;
    struct Node_n *next;
} Node_n;

/* Прототипы функций для списка-словаря */
Node *create_node(const char *new_word);
void add_first(Node **head, Node *new_node);
void add_before(Node **head, Node *next_n, Node *new_node);
Node *find_place(Node *head, const char *new_word);
Node *find(Node *head, const char *new_word);
void remove_item(Node *prev);

/* Прототипы функций для списка чисел */
Node_n *create_node_(int num);
void add_first_(Node_n **head, Node_n *new_node);
void add_after_(Node_n *prev, Node_n *new_node);
void add_last_(Node_n **head, Node_n *new_node);

/* Вспомогательные функции */
void print_color(const char *str, const char *color);
void pause(bool _exit);
void random_word(char *buffer, int size);
FILE *create_file(const char *f_name);
void fill_txt_file(FILE* f);

#endif