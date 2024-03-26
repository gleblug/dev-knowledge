#pragma once
#include "singlylinkedlist.h"


template <typename T>
SinglyNode<T> *middle_node(SinglyLinkedList<T>& obj)
{
    if (obj.empty())
        throw error::container_is_empty;

    auto fast = obj.head->next;
    auto slow = obj.head->next;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}