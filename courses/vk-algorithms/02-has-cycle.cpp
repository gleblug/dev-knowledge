#include "singlylinkedlist.h"
#include <iostream>
#include <cassert>


template <typename T>
bool has_cycle(const SinglyLinkedList<T>& obj)
{
    auto slow = obj.head;
    auto fast = obj.head->next;

    while (slow != fast)
    {
        if (slow == nullptr || fast == nullptr)
            return false;
        if (fast->next == nullptr)
            return false;
        slow = slow->next;
        fast = fast->next->next;
    }   
    return true;
}

int main(int argc, char const *argv[])
{
    SinglyLinkedList<int> sll1{1, 2, 3, 4, 5, 6, 7, 8, 9};
    SinglyLinkedList<int> sll2{1, 2, 3, 4, 5, 6, 7, 8, 9};
    SinglyLinkedList<int> sll3{};

    sll1.at(8)->next = sll1.at(5);

    assert(has_cycle(sll1) == true);
    assert(has_cycle(sll2) == false);
    assert(has_cycle(sll3) == false);

    return 0;
}