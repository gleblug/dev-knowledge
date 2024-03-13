#include "singlylinkedlist.h"
#include <iostream>


int main(int argc, char const *argv[])
{
    SinglyLinkedList<int> sll{1, 2, 3, 4};
    // SinglyLinkedList<int> sll;

    std::cout << sll;

    return 0;
}