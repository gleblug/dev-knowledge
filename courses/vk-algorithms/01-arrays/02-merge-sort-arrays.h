#include <iterator>
#include <vector>


template <typename InputIt, typename OutputIt>
inline void merge_sort_arrays(
    const InputIt first1, const InputIt last1,
    const InputIt first2, const InputIt last2,
    OutputIt out )
{
    auto cur1 = first1;
    auto cur2 = first2;
    
    while (cur1 < last1 && cur2 < last2)
    {
        if (*cur1 < *cur2)
            *(out++) = *(cur1++);
        else
            *(out++) = *(cur2++);
    }
    while (cur1 < last1)
        *(out++) = *(cur1++);
    while (cur2 < last2)
        *(out++) = *(cur2++);
}

template <typename T>
inline void merge_sort_arrays_second(std::vector<T> &vec1, const std::vector<T> &vec2)
{
    if (vec2.empty())
        return;
    if (vec1.empty())
    {
        vec1 = vec2;
        return;
    }

    auto cur2 = vec2.cend() - 1;
    vec1.resize(vec1.size() + vec2.size(), 0);
    auto cur1 = vec1.cend() - vec2.size() - 1;
    auto out = vec1.end() - 1;

    while (cur2 >= vec2.cbegin())
    {
        if ((cur1 >= vec1.cbegin()) && (*cur1 > *cur2))
            *(out--) = *(cur1--);
        else
            *(out--) = *(cur2--);
    }
}


// write triple pointers merge sort (increase capacity of first array)