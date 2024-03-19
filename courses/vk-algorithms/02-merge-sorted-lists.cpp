#include "singlylinkedlist.h"
#include <cassert>


// memory cost equal O(1)
// lists should be sorted in increasing order (simple merge sort)
template <typename T>
void merge_sorted_lists(SinglyLinkedList<T> &objTo, SinglyLinkedList<T> &&objFrom)
{
    SinglyNode<T> *curTo = objTo.head;
    SinglyNode<T> *firstFrom = objFrom.head->next;

    while (curTo->next != nullptr && firstFrom != nullptr)
    {
        if (curTo->next->data > firstFrom->data)
        {
            objFrom.head->next = firstFrom->next;
            firstFrom->next = curTo->next;
            curTo->next = firstFrom;
            firstFrom = objFrom.head->next;
        } else
        {
            curTo = curTo->next;
        }
    }

    curTo->next = objFrom.head->next;
    objFrom.head->next = nullptr;

    objTo.m_size = objTo.size() + objFrom.size();
    objFrom.m_size = 0;
}

int main(int argc, char const *argv[])
{
    SinglyLinkedList<int> sll1{1, 4, 5, 8, 10};
    SinglyLinkedList<int> sll2{2, 3, 4, 8, 10, 12};

    // result will be recorded to first list
    // move second parameter prevent it's further reading
    merge_sorted_lists(sll1, std::move(sll2));

    std::cout << sll1 << std::endl;

    return 0;
}