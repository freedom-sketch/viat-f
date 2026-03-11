#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include "linked_list.h"

#define FILE_NAME "text.txt"
#define A 2 /* Минимальный размер слова в символах */
#define B 30 /* Максимальный размер слова в символах */

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
    print_color("Задание 1\n", GRN);
    printf("Вывести на экран количество различных "
            "слов, т.е. количество элементов списка\n\n");

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

    printf(LBLE "Различные слова из файла %s в алфавитном порядке:\n" RESET, FILE_NAME);

    Node *p = head;
    words_count = 1;
    while (p != NULL) {
        printf("%d. %s\n", words_count++, p->word);

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
    print_color("Задание 2\n", GRN);
    printf("Создать список из десяти элементов и вывести его на экран. "
            "Затем вывести только четные элементы списка\n\n");

    srand(time(NULL));

    /* Создаем список из 10 "случайных" слов */
    Node *head = NULL;
    for (int i = 0; i < 10; i++) {
        int word_size = A + rand() % (B - A + 1);
        char word[word_size];
        random_word(word, word_size);

        Node *existing = find(head, word);
        if (existing) {
            existing->count++;
            continue;
        }

        Node *new_node = create_node(word);

        if (i == 0) {
            head = new_node;
        } else {
            Node *place = find_place(head, word);
            add_before(&head, place, new_node);
        }
    }

    /* Выводим весь список */
    print_color("Все элементы списка:\n", LBLE);
    Node *p = head;
    int num = 1;
    while (p != NULL) {
        printf("%d. %s\n", num++, p->word);
        p = p->next;
    }

    /* Выводим только четные элементы */
    print_color("\nЧетные элементы списка:\n", LBLE);
    p = head;
    num = 1;
    while (p != NULL) {
        if (num % 2 == 0) printf("%d. %s\n", num, p->word);

        Node *current = p;
        p = p->next;
        free(current->word);
        free(current);

        num++;
    }

    return;
}

void task_three()
{
    print_color("Задание 3\n", GRN);
    printf("Дан односвязный список. Найти максимальный и минимальный элементы в списке\n\n");

    srand(time(NULL));

    int list_size = 50 + rand() % (100 - 50 + 1);

    Node_n *head = NULL;
    for (int i = 0; i < list_size; i++) {
        Node_n *new_node = create_node_(rand());
        add_last_(&head, new_node);
    }

    print_color("Весь список:\n", LBLE);
    int num = 1;
    Node_n *p = head;
    while (p != NULL) {
        printf("%d) %d\n", num++, p->num);
        p = p->next;
    }

    p = head;
    num = 1;
    int num_min = 1, num_max = 1;
    int min = head->num, max = head->num;
    while (p != NULL) {
        if (p->num < min) {
            min = p->num;
            num_min = num;
        } else if (p->num > max) {
            max = p->num;
            num_max = num;
        }

        num++;
        p = p->next;
    }

    print_color("\nМинимальный элемент: ", LBLE);
    printf("%d (на позиции %d)\n", min, num_min);

    print_color("Максимальный элемент: ", LBLE);
    printf("%d (на позиции %d)\n", max, num_max);

    return;
}

int main(void)
{
    system("chcp 65001 > nul");

    task_one(FILE_NAME);

    pause();

    task_two();

    pause();

    task_three();

    printf("\nНажмите Enter для выхода...");
    getchar();

    return 0;
}