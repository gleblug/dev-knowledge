#pragma once
#include <string>
#include <stack>


inline bool is_palindrome_stack(const std::string &word)
{
    std::stack<char> stack;
    for(const char letter : word)
        stack.push(letter);
    for(const char letter : word)
    {
        if (stack.top() != letter)
            return false;
        stack.pop();
    }
    return true;
}

inline bool is_palindrome_two_pointers(const std::string &word)
{
    if (word.size() < 2)
        return true;
    std::size_t left = 0;
    std::size_t right = word.size() - 1;
    while (left < right)
        if (word[left++] != word[right--])
            return false;
    return true;
}