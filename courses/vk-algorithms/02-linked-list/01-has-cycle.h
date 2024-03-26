#pragma once
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