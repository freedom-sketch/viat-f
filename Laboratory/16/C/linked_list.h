#ifndef LINKED_LIST
#define LINKED_LIST

#define GRN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"
#define STR_SIZE 128


/* Структура узла односвязного списка */
typedef struct Node {
    char *word; /* Память будет выделяться в момент создания узла */
    int count;
    struct Node *next;
} Node;

/* Прототипы функций для списка */
Node *create_node(const char *new_word);
void add_first(Node **head, Node *new_node);
void add_before(Node **head, Node *next_n, Node *new_node);
Node *find_place(Node *head, const char *new_word);
Node *find(Node *head, const char *new_word);
void remove_item(Node *prev);

/* Вспомогательные функции */
void random_cyrillic_letter(char *buffer);
void print_color(const char *str, const char *color);
void pause();

#endif