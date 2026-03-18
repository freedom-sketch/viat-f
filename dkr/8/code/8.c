#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "clr_linked_list.h"

static bool file_exists(const char *filename)
{
    FILE *f = fopen(filename, "r");
    if (f != NULL) {
        fclose(f);
        return true;
    };
    return false;
}

static bool open_file(const char *filename)
{
    if (!file_exists(filename)) return false;
    char command[256];
    #if defined(_WIN32) || defined(_WIN64)
        snprintf(command, sizeof(command), "start %s", filename);
    #elif defined(__linux__)
        snprintf(command, sizeof(command), "xdg-open %s", filename);
    #endif
    system(command);
    return true;
}

int main(void)
{
    system(SET_UTF8);

    static Node list[SIZE];
    int head = -1;

    bool run = true;
    int state = 0;
    while (run) {
        fflush(stdin);
        int action;
        switch (state)
        {
        case 0:
            system(CLEAR);
            print_color("Реализация элементарных структур данных "
                "на основе статической памяти\n\n", GRN);
            printf("Список: ");
            print_list(list, head);
            printf("\nВыберите действие:\n");
            print_color("[1] Добавить в конец списка\n"
                        "[2] Взять с начала списка\n"
                        "[3] Просмотреть код программы\n"
                        "[4] Выйти\n", LBLE);
            printf("\nДействие: ");

            scanf(" %c", &action);
            switch (action)
            {
            case '1':
                system(CLEAR);
                char num[100];
                printf("Введите число (не более %lld): ", LLONG_MAX);
                scanf("%s", num);
                int push_status = push(list, &head, strtoll(num, NULL, 10));
                if (push_status != 0) {
                    print_color("В списке нет места\n\n", RED);
                    pause();
                }
                break;
            case '2':
                system(CLEAR);
                long long pop_num = pop(list, &head);
                if (pop_num != LLONG_MAX) {
                    print_color("Было взято число ", LBLE);
                    printf("%lld\n\n", pop_num);
                    pause();
                } else {
                    print_color("Список пуст\n\n", RED);
                    pause();
                }
                break;
            case '3':
                state = 1;
                break;
            case '4':
                exit(0);
                break;
            default:
                break;
            }
            break;

        case 1:
            system(CLEAR);
            printf("Выберите файл:\n\n"
                    "[1] " LBLE "%s\n" RESET
                    "[2] " LBLE "clr_linked_list.c\n" RESET
                    "[3] " LBLE "clr_linked_list.h\n" RESET
                    "[4] Назад\n", __FILE_NAME__);
            printf("Действие: ");
            scanf(" %c", &action);

            switch(action)
            {
                case '1':
                    if (!open_file(".\\code\\" __FILE_NAME__)) {
                        print_color("Не удалось найти файл\n", RED);
                        pause();
                    }
                    break;
                case '2':
                    if (!open_file(".\\code\\clr_linked_list.c")) {
                        print_color("Не удалось найти файл\n", RED);
                        pause();
                    }
                    break;
                case '3':
                    if (!open_file(".\\code\\clr_linked_list.h")) {
                        print_color("Не удалось найти файл\n", RED);
                        pause();
                    }
                    break;
                case '4':
                    state = 0;
                    break;
                default:
                    break;
            }
            default:
                break;
        }
    }
}