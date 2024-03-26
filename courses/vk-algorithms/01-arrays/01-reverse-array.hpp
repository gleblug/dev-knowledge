#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>


template <typename InputIt>
inline void reverse_array(InputIt first, InputIt last)
{
    while (first < last)
        std::swap(*(first++), *(--last));
}

template <typename InputIt>
inline void reverse_part_of_array(InputIt first, InputIt last, size_t k)
{
    auto n = std::distance(first, last);
    if (n <= 0 || k >= n)
        return;
    reverse_array(first, last);
    reverse_array(first, std::next(first, n - k));
    reverse_array(std::next(first, n - k), last);
}