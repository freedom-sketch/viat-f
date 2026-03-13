#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define IN_FILE_NAME "numbers.txt"
#define OUT_FILE_NAME "result.txt"

void process_number(Stack *s, const char *num_str)
{
    int num = atoi(num_str);
    push(s, num);
}

int main(void)
{
    system(SET_UTF8);

    print_color("Задание 1\n", GRN);
    printf("В файле %s записан список чисел. "
        "Необходимо переписать его в другой файл "
        "в обратном порядке.\n\n", IN_FILE_NAME);
    
    FILE *input_file = fopen(IN_FILE_NAME, "r");
    if (input_file == NULL) {
        print_color("Не удалось прочитать файл " IN_FILE_NAME "\n", RED);
        printf("\nНажмите Enter для выхода...");
        getchar();
        return 1;
    }

    Stack *stack = init_stack();

    int ch, i = 0;
    char num_str[MAX_NUM_SIZE];
    while ((ch = fgetc(input_file)) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            if (i > 0) {
                num_str[i] = '\0';
                process_number(stack, num_str);
                i = 0;
            }
            continue;
        }

        if (i < MAX_NUM_SIZE - 1) {
        num_str[i++] = ch;
        }
    }
    if (i > 0) {
        num_str[i] = '\0';
        process_number(stack, num_str);
    }
    fclose(input_file);

    FILE *output_file = fopen("result.txt", "w");
    if (output_file == NULL) {
        printf("Не удалось создать файл для записи\n");
        return 1;
    }

    print_color("Числа из " IN_FILE_NAME " перенесены в "
                OUT_FILE_NAME " в такой последовательности:\n", LBLE);
    while (!is_empty_stack(stack)) {
        int val = pop(stack);
        printf("%d ", val);
        fprintf(output_file, "%d ", val);
    }
    fclose(output_file);

    free(stack->tags);
    free(stack);

    printf("\n\nНажмите Enter для выхода...");
    getchar();
}