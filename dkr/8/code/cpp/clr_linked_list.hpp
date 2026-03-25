#ifndef CIRCULAR_LINKED_LIST_HPP
#define CIRCULAR_LINKED_LIST_HPP

#include <iostream>
#include <string>
#include <limits>

#if defined(_WIN32) || defined(_WIN64)
    #define SET_UTF8 "chcp 65001 > nul"
    #define CLEAR "cls"
#else
    #define SET_UTF8 "clear"
    #define CLEAR "clear"
#endif

const std::string GRN = "\033[32m";
const std::string RED = "\033[31m";
const std::string LBLE = "\033[36m";
const std::string RESET = "\033[0m";

const int MAX_SIZE = 30;

struct Node {
    long long data = 0;
    bool busy = false;
    int next = -1;
};

class CircularList {
private:
    Node nodes[MAX_SIZE];
    int head = -1;

    int find_tail() const;

public:
    bool push(long long data);
    long long pop();
    void print() const;
    void print_colored(const std::string& text, const std::string& color) const;
};

void pause();

#endif