#include <iostream>
#include <cstdlib>
#include <filesystem>
#include "clr_linked_list.hpp"

namespace fs = std::filesystem;

void open_file(const std::string& filename) {
    if (!fs::exists(filename)) {
        std::cout << RED << "Файл не найден: " << filename << RESET << std::endl;
        pause();
        return;
    }
    std::string command;
#if defined(_WIN32) || defined(_WIN64)
    command = "start " + filename;
#else
    command = "xdg-open " + filename;
#endif
    std::system(command.c_str());
}

int main() {
    std::system(SET_UTF8);
    CircularList myList;
    int state = 0;

    while (true) {
        std::system(CLEAR);
        if (state == 0) {
            myList.print_colored("Реализация элементарных структур данных на основе статической памяти\n\n", GRN);
            std::cout << "Список: ";
            myList.print();
            
            std::cout << "\nВыберите действие:\n";
            myList.print_colored("[1] Добавить в конец\n[2] Взять из начала\n[3] Код программы\n[4] Выход\n", LBLE);
            std::cout << "\nДействие: ";

            char choice;
            std::cin >> choice;

            if (choice == '1') {
                std::string input;
                std::cout << "Введите число: ";
                std::cin >> input;
                try {
                    long long val = std::stoll(input);
                    if (!myList.push(val)) {
                        myList.print_colored("Ошибка: нет места!\n", RED);
                        pause();
                    }
                } catch (...) {
                    myList.print_colored("Ошибка: неверный формат числа!\n", RED);
                    pause();
                }
            } else if (choice == '2') {
                long long result = myList.pop();
                if (result != std::numeric_limits<long long>::max()) {
                    std::cout << LBLE << "Извлечено: " << RESET << result << "\n\n";
                    pause();
                } else {
                    myList.print_colored("Список пуст!\n", RED);
                    pause();
                }
            } else if (choice == '3') {
                state = 1;
            } else if (choice == '4') {
                break;
            }
        } else if (state == 1) {
            std::cout << "Просмотр файлов:\n"
                      << "[1] 8.cpp\n"
                      << "[2] clr_linked_list.cpp\n"
                      << "[3] clr_linked_list.hpp\n"
                      << "[4] Назад\n"
                      << "Действие: ";
            char fileChoice;
            std::cin >> fileChoice;
            
            switch (fileChoice) {
                case '1': open_file(".\\code\\cpp\\8.cpp"); break;
                case '2': open_file(".\\code\\cpp\\clr_linked_list.cpp"); break;
                case '3': open_file(".\\code\\cpp\\clr_linked_list.hpp"); break;
                case '4': state = 0; break;
            }
        }
    }

    return 0;
}