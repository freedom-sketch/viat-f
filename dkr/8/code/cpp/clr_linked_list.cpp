#include "clr_linked_list.hpp"

int CircularList::find_tail() const {
    if (head == -1) return -1;
    int current = head;
    while (nodes[current].next != head) {
        current = nodes[current].next;
    }
    return current;
}

bool CircularList::push(long long data) {
    int new_idx = -1;
    for (int i = 0; i < MAX_SIZE; ++i) {
        if (!nodes[i].busy) {
            new_idx = i;
            break;
        }
    }

    if (new_idx == -1) return false;

    nodes[new_idx].data = data;
    nodes[new_idx].busy = true;

    if (head == -1) {
        head = new_idx;
        nodes[new_idx].next = new_idx;
    } else {
        int tail = find_tail();
        nodes[new_idx].next = head;
        nodes[tail].next = new_idx;
    }
    return true;
}

long long CircularList::pop() {
    if (head == -1) return std::numeric_limits<long long>::max();

    int head_idx = head;
    long long data = nodes[head_idx].data;
    int tail = find_tail();

    if (tail == head_idx) {
        nodes[head_idx].busy = false;
        head = -1;
    } else {
        head = nodes[head_idx].next;
        nodes[tail].next = head;
        nodes[head_idx].busy = false;
    }
    return data;
}

void CircularList::print() const {
    if (head == -1) {
        std::cout << "Список пуст" << std::endl;
        return;
    }

    int current = head;
    std::cout << "[ ";
    do {
        std::cout << nodes[current].data << " ";
        current = nodes[current].next;
    } while (current != head);
    std::cout << "]" << std::endl;
}

void CircularList::print_colored(const std::string& text, const std::string& color) const {
    std::cout << color << text << RESET;
}

void pause() {
    std::cout << "Нажмите Enter, чтобы продолжить...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}