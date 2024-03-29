#pragma once
#include <queue>
#include <string>


inline bool is_subsequence_queue(const std::string &a, const std::string &b)
{
    std::queue<char> queue;
    for (const char el : a)
        queue.push(el);
    
    for (const char el : b)
    {
        if (queue.empty())
            return true;
        if (el == queue.front())
            queue.pop();
    }

    return queue.empty();
}

inline bool is_subsequence_two_pointers(const std::string &a, const std::string &b)
{
    if (a.empty())
        return true;
    
    std::size_t i = 0;
    for (const char el : b)
    {
        if (a.at(i) == el)
            ++i;
        if (a.size() == i)
            return true;
    }

    return false;
}