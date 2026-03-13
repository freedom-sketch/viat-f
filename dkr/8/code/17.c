#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "clr_linked_list.h"

int main(void)
{
    system(SET_UTF8);

    static Node list[SIZE];
    int head = -1;

    bool run = true;
    while (run) {
        system(CLEAR);

        print_color("Реализация элементарных структур данных "
            "на основе статической памяти\n\n", GRN);
        
        printf("Список: ");
        print_list(list, head);

        printf("\nВыберите действие:\n");
        print_color("[1] Добавить в конец списка\n"
                    "[2] Взять с конца списка\n"
                    "[3] Выйти\n", LBLE);

        printf("\nДействие: ");

        int action = getchar();
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
            exit(0);
        
        default:
            break;
        }
    }
}