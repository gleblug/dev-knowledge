#pragma once
#include <exception>
#include <initializer_list>
#include <iostream>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>

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

    Node *head;
    std::size_t m_size;

    SinglyLinkedList() :
        head{new Node},
        m_size{0} {}

    SinglyLinkedList(const SinglyLinkedList& other) = delete;

    SinglyLinkedList(SinglyLinkedList&& other) :
        head(std::exchange(other.head, new Node{})),
        m_size(std::exchange(other.m_size, 0))
    {}

    // TODO: add copy c-tor

    SinglyLinkedList(const std::initializer_list<T>& list) :
        head{new Node},
        m_size{0}
    {
        for (const T& elem : list)
            append_back(elem);
    }

    SinglyLinkedList(Node *first) :
        head{new Node},
        m_size{0}
    {
        head->next = first;
        calculate_size();
    }

    ~SinglyLinkedList()
    {
        // if (empty())
        // {
        //     delete head;
        //     return;
        // }
        
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

    bool operator==(const SinglyLinkedList &other)
    {
        if (size() != other.size())
            return false;

        auto cur_other = other.head->next;
        auto cur_this = head->next;

        for (auto i = 0; i < size(); ++i)
        {
            if (cur_other->data != cur_this->data)
                return false;
            cur_other = cur_other->next;
            cur_this = cur_this->next;
        }
        return true;
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