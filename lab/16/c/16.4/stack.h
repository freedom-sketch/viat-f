#ifndef STACK
#define STACK

#if defined(_WIN32) || defined(_WIN64)
    #define SET_UTF8 "chcp 65001 > nul"
#elif defined(__linux__)
    #define SET_UTF8 "echo"
#endif

#define GRN "\033[32m"
#define RED "\033[31m"
#define LBLE "\033[36m"
#define RESET "\033[0m"

#define START_CAPACITY 10
#define MAX_NUM_SIZE 50

typedef struct Stack {
    int *tags;
    int size;
    int capacity;
} Stack;

Stack *init_stack();
/* Перевыделение памяти под tags в случае переполнения */
void grow_stack(Stack *s);
/* Добавление числа в стэк */
void push(Stack *s, int x);
/* Получение последнего элемента стэка */
int pop(Stack *s);
/* Проверка стэка на пустоту */
bool is_empty_stack(Stack *s);

/* Цветной вывод */
void print_color(const char *str, const char *color);

#endif