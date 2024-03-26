#pragma once
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
    obj.calculate_size();
}