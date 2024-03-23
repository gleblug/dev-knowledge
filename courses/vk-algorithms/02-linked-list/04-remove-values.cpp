#include "singlylinkedlist.h"


template <typename T>
void remove_values(SinglyLinkedList<T>& obj, const T& value)
{
    auto prev = obj.head;
    auto cur = obj.head->next;

    while (cur != nullptr)
    {
        if (cur->data == value)
        {
            prev->next = cur->next;
            delete cur;
        }
        else
        {
            prev = prev->next;
        }
        cur = prev->next;
    }
}

int main(int argc, char const *argv[])
{
    SinglyLinkedList<int> sll;
    int val;

    std::cin >> sll >> val;
    remove_values(sll, val);
    std::cout << sll;

    return 0;
}