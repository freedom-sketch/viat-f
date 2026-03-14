#include <stdio.h>
#include <string.h>
#include "memtracker.h"

int main() {
    system("chcp 65001 > nul");

    char *s1 = malloc(20);
    char *s2 = malloc(30);
    char *s3 = malloc(40);

    printf("Выделено 3 блока на 20, 30 и 40 байт. Освобождаем только 1-й и 3-й\n");
    free(s1);
    free(s3);

    printf("--- Тест двойного освобождения: ---\n");
    free(s1); 
    
    printf("--- Выход из main() ---\n");
}