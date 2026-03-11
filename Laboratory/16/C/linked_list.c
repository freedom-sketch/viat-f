#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linked_list.h"

/* Создает узел списка */
Node *create_node(const char *new_word)
{
    /* Выделяем память под узел */
    Node *node = malloc(sizeof(Node));
    if (!node) return NULL;

    size_t len = strlen(new_word);
    /* Выделяем память, необходимую под слово */
    node->word = malloc(len + 1);
    if (!node->word) {
        free(node);
        return NULL;
    }

    /* Записываем слово в выделенную память */
    strcpy(node->word, new_word);

    node->count = 1;
    node->next = NULL;

    return node;
}

/* Добавляет узел в голову списка */
void add_first(Node **head, Node *new_node)
{
    new_node->next = *head;
    *head = new_node;
}

/* Добавляет узел после узла prev */
void add_after(Node *prev, Node *new_node)
{
    new_node->next = prev->next;
    prev->next = new_node;
}

/* Добавляет узел перед узлом next_n*/
void add_before(Node **head, Node *next_n, Node *new_node)
{
    if (next_n == *head) {
        add_first(head, new_node);
    } else {
        Node *pp = *head;
        while (pp != NULL && pp->next != next_n)
            pp = pp->next;

        if (pp != NULL) add_after(pp, new_node);
    }
}

/* Добавляет узел в конец списка */
void add_last(Node **head, Node *new_node)
{
    if (*head == NULL) {
        add_first(head, new_node);
    } else {
        Node *pp = *head;
        while (pp->next != NULL)
            pp = pp->next;

        add_after(pp, new_node);
    }
}

/* Удаляет узел, следующий за prev */
void remove_item(Node *prev)
{
    if (!prev || !prev->next) return;

    Node *to_delete = prev->next;
    prev->next = to_delete->next;

    free(to_delete->word);
    free(to_delete);
}

/* Возвращает адрес узла, перед которым необходимо добавить слово, либо NULL, 
если слово должно быть вставлено в конец списка */
Node *find_place(Node *head, const char *new_word)
{
    Node *pp = head;
    while (pp != NULL && strcmp(new_word, pp->word) > 0)
        pp = pp->next;
    return pp;
}

/* Возвращает адрес узла, который содержит искомое слово либо NULL, если слово не найдено */
Node *find(Node *head, const char *new_word)
{
    Node *pp = head;
    while (pp != NULL && strcmp(new_word, pp->word) != 0)
        pp = pp->next;
    return pp;
}

/* Красивый цветной вывод */
void print_color(const char *str, const char *color)
{
    printf("%s%s%s", color, str, RESET);
}

void random_cyrillic_letter(char *buffer)
{
    int pos = rand() % 32;

    if (pos < 16) {
        buffer[0] = 208;
        buffer[1] = 176 + pos;
    } else {
        buffer[0] = 209;
        buffer[1] = 128 + (pos - 16);
    }

    buffer[2] = '\0';

    return;
}

void pause()
{
    printf("\nНажмите Enter для перехода к следующему заданию...");
    getchar();
    system("cls");
    return;
}