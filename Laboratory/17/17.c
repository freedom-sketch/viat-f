#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "clr_linked_list.h"

int main(void)
{
    system("chcp 65001 > nil");

    static Node list[SIZE];
    int head = -1;

    bool run = true;
    while (run) {
        system("cls");

        print_color("Реализация элементарных структур данных "
            "на основе статической памяти\n\n", GRN);
        
        printf("Список: ");
        print_list(list, head);

        printf("\nВыберите действие:\n");
        print_color("[1] Добавить в конец списка\n", LBLE);
        print_color("[2] Взять с конца списка\n", LBLE);

        printf("\nДействие: ");

        int action = getchar();

        switch (action)
        {
        case '1':
            system("cls");
            char num[100];

            printf("Введите число (не более %lld): ", LONG_LONG_MAX);

            scanf("%s", num);

            int push_status = push(list, &head, strtoll(num, NULL, 10));
            if (push_status != 0) {
                print_color("В списке нет места\n\n", RED);
                pause();
            }
            break;
        
            case '2':
                system("cls");
                long long pop_num = pop(list, &head);
                if (pop_num != LONG_LONG_MAX) {
                    print_color("Было взято число ", LBLE);
                    printf("%lld\n\n", pop_num);
                    pause();
                } else {
                    print_color("Список пуст\n\n", RED);
                    pause();
                }
        
        default:
            break;
        }
    }
}