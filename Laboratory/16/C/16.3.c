#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include "linked_list.h"

#define FILE_NAME "text.txt"

/* Обработка слова */
void process_word(Node **head, const char *word, int *words_count) {
    if (!word || word[0] == '\0') {
        return;
    }

    Node *existing = find(*head, word);
    if (existing) {
        existing->count++;
        return;
    }

    Node *new_node = create_node(word);

    if (*words_count == 0) {
        *head = new_node;
    } else {
        Node *place = find_place(*head, word);
        add_before(head, place, new_node);
    }

    (*words_count)++;
}

/* Задание 1.
Составить из описанных выше функций программу, реализующую алфавитно-частотный словарь.
Вывести на экран количество различных слов, т.е. количество элементов списка. */
void task_one(const char *file_name)
{
    FILE *f = fopen(FILE_NAME, "r");
    if (f == NULL) {
        print_color("Не удалось прочитать файл " FILE_NAME "\n", RED);
        printf("\nНажмите Enter для выхода...");
        getchar();
        exit(1);
    }
    
    Node *head = NULL;
    char str[STR_SIZE];
    int ch, i = 0, words_count = 0;
    while ((ch = fgetc(f)) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            str[i] = '\0';
            process_word(&head, str, &words_count);
            i = 0;
        } else {
            str[i++] = ch;
        }
    }

    if (i > 0) {
        str[i] = '\0';
        process_word(&head, str, &words_count);
    }

    print_color("Задание 1\n", GRN);
    printf("Различные слова из файла %s в алфавитном порядке:\n\n", FILE_NAME);

    Node *p = head;
    while (p != NULL) {
        printf("%s\n", p->word);

        Node *current = p;
        p = p->next;
        
        free(current->word);
        free(current);
    }

    fclose(f);

    return;
}

void task_two()
{
    int a = 2; /* Минимальное количество букв в слове */
    int b = 120; /* Максимальное количество букв в слове */

    Node *head = NULL;
    for (int node_count = 0; node_count != 10; node_count++) {
        int num_letters = a + rand() % (b - a + 1);
        char str[num_letters*2];
        for (int i = 0; num_letters*2 > i; i++) {
            char *letter;
            random_cyrillic_letter(letter);
            str[i++] = letter[0];
            str[i] = letter[1];
        }

        if (node_count == 0) {
            Node *new_node = create_node();
        }
    }
}

int main(void)
{
    system("chcp 65001 > nul");
    srand(time(NULL));

    task_one(FILE_NAME);

    pause();

    task_two();

    printf("\nНажмите Enter для выхода...");
    getchar();

    return 0;
}