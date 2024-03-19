#include <exception>
#include <initializer_list>
#include <iostream>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>

namespace error
{
    inline std::out_of_range index_out_of_range ("Index out of range");
    inline std::logic_error  container_is_empty ("Container is empty");
    inline std::logic_error  node_not_found     ("Node not found");
} // error


template <typename T>
class SinglyLinkedList
{
public:
    struct Node 
    {
        T data;
        Node *next = nullptr;
    };

    Node *head = new Node;
    std::size_t m_size = 0;

    SinglyLinkedList() = default;

    // TODO: add copy c-tor

    SinglyLinkedList(const std::initializer_list<T>& list)
    {
        for (const T& elem : list)
            append_back(elem);
    }

    SinglyLinkedList(Node *first)
    {
        head->next = first;
        calculate_size();
    }

    ~SinglyLinkedList()
    {
        auto node = head;
        auto next = head->next;
        for (auto i = 0; i < size(); ++i)
        {
            delete node;
            node = next;
            next = node->next;
        }
        delete node;
    }

    std::size_t size() const
    {

        return m_size;
    }

    void calculate_size()
    {
        std::size_t cntr = 0;
        auto node = head->next;
        while (node != nullptr)
        {
            ++cntr;
            node = node->next;
        }
        m_size = cntr;
    }

    void append_front(const T& elem)
    {
        auto first = new Node{elem};
        auto second = head->next;
        head->next = first;
        first->next = second;
        ++m_size;
    }

    void append_back(const T& elem)
    {
        auto last = new Node{elem};
        auto cur_node = head;
        while (cur_node->next != nullptr)
            cur_node = cur_node->next;
        cur_node->next = last;
        ++m_size;
    }

    // bool insert(Node *after, const T& elem)
    // {
    // }

    // void erase(const std::size_t from, const std::size_t to)
    // {
    // }

    Node *at(const std::size_t idx)
    {
        if (idx >= size())
            throw error::index_out_of_range;

        auto node = head->next;
        for (std::size_t cntr = 0; cntr < idx; ++cntr)
            node = node->next;

        return node;
    }

    bool empty() const
    {
        return (head->next == nullptr);
    }
};

template <typename T>
using SinglyNode = typename SinglyLinkedList<T>::Node;

template <typename T>
std::ostream& operator<<(std::ostream& os, const SinglyLinkedList<T>& obj)
{
    os << "SinglyLinkedList[";
    if (obj.empty())
    {
        os << "]";
        return os;
    }

    auto node = obj.head->next;
    while (node->next != nullptr)
    {
        os << node->data << ", ";
        node = node->next;
    }
    os << node->data << "]";
    return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, SinglyLinkedList<T>& obj)
{
    std::string input;
    std::getline(is, input);
    std::istringstream iss(input);
    T data;
    while (iss >> data)
        obj.append_back(data);

    return is;
}