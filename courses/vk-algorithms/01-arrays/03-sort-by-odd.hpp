#include <cstdint>
#include <iterator>
#include <vector>
#include <iostream>


// move all odd numbers to back of array
template <typename InputIt>
inline void sort_by_odd(InputIt first, InputIt last)
{
    auto containOdd = [](InputIt it){ return (*it) % 2 == 1; };
    auto oddIt = first;
    auto evenIt = first;

    if (containOdd(first))
        while (containOdd(evenIt) && (evenIt < last))
            ++evenIt;
    else
        while (!containOdd(oddIt) && (oddIt < last))
            ++oddIt;

    if (oddIt == last || evenIt == last)
        return;
    else
    {
        std::swap(*evenIt, *oddIt);
        std::swap(evenIt, oddIt);
    }

    while (true)
    {
        while (containOdd(++oddIt))
            if (oddIt == last)
                break;
        while (!containOdd(++evenIt))
            if (evenIt == last)
                break;
        
        if (oddIt == last || evenIt == last)
            break;
        else
            std::swap(*oddIt, *evenIt);
    }

}