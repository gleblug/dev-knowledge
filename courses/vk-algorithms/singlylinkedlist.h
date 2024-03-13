#include <initializer_list>
#include <iostream>
#include <ostream>


template <typename T>
struct SinglyNode 
{
    T data;
    SinglyNode *next = nullptr;
};

template <typename T>
class SinglyLinkedList
{
public:
    SinglyLinkedList() = default;

    SinglyLinkedList(const std::initializer_list<T>& list):
        head{new SinglyNode<T>}
    {
        for (const T& elem : list)
            append_back(elem);
    }

    void append_back(const T& elem)
    {
        auto new_node = new SinglyNode<T>{elem};
        if (head->next == nullptr)
        {
            head->next = new_node;
            return;
        }

        auto cur_node = head;
        while (cur_node->next != nullptr)
            cur_node = cur_node->next;

        cur_node->next = new_node;
    }

    SinglyNode<T> *middle_node()
    {
        auto slow = head;
        auto fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const SinglyLinkedList<T>& obj);

    SinglyNode<T> *head;
};


template <typename T>
std::ostream& operator<<(std::ostream& os, const SinglyLinkedList<T>& obj)
{
    auto node = obj.head;
    while (node->next != nullptr)
        os << node->data << ' ';
    return os;
}