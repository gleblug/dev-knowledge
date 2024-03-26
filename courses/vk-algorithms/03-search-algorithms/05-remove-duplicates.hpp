#pragma once
#include <string>

// stack-like solution
// copy std::string
inline std::string remove_duplicates(const std::string &str)
{
    std::string res;
    for (const char el : str)
    {
        if (!res.empty() && (el == res.back()))
            res.pop_back();
        else
            res.push_back(el);
    }
    return res;
}