#pragma once
#include "singlylinkedlist.hpp"
#include <cassert>


// memory cost equal O(1)
// lists should be sorted in increasing order (simple merge sort)
template <typename T>
inline void merge_sorted_lists(SinglyLinkedList<T> &objTo, SinglyLinkedList<T> &&objFrom)
{
    SinglyNode<T> *curTo = objTo.head;
    SinglyNode<T> *firstFrom = objFrom.head->next;

    while ((curTo->next != nullptr) && (firstFrom != nullptr))
    {
        if (curTo->next->data > firstFrom->data)
        {
            objFrom.head->next = firstFrom->next;
            firstFrom->next = curTo->next;
            curTo->next = firstFrom;
            firstFrom = objFrom.head->next;
        } else {
            curTo = curTo->next;
        }
    }

    while (curTo->next != nullptr)
        curTo = curTo->next;
    
    curTo->next = objFrom.head->next;
    objFrom.head->next = nullptr;

    objTo.m_size = objTo.size() + objFrom.size();
    objFrom.m_size = 0;
}