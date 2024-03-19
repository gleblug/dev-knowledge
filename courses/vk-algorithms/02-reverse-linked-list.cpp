#include "singlylinkedlist.h"
#include <iostream>


template <typename T>
void reverse_linked_list(SinglyLinkedList<T>& obj)
{
    if (obj.size() < 2)
        return;

    auto prev = obj.head->next;
    auto cur = prev->next;
    auto next = cur;

    prev->next = nullptr;
    while (cur->next != nullptr)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    cur->next = prev;
    obj.head->next = cur;
}

int main(int argc, char const *argv[])
{
    SinglyLinkedList<int> sll;

    std::cin >> sll;
    reverse_linked_list(sll);
    std::cout << sll;

    return 0;
}