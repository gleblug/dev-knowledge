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
    std::size_t l = 0;
    std::size_t r = word.size() - 1;
    while (l < r)
        if (word[l++] != word[r--])
            return false;
    return true;
}