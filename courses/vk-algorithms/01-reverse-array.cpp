#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>


template <typename InputIt, typename OutputIt>
void reverse_array(InputIt first, OutputIt last)
{
    while (first < last)
        std::swap(*(first++), *(--last));
}

template <typename InputIt, typename OutputIt>
void reverse_part_of_array(InputIt first, OutputIt last, size_t firstIdx, size_t lastIdx)
{
    if ((firstIdx >= lastIdx) || (lastIdx > std::distance(first, last)))
        return;
    reverse_array(std::next(first, firstIdx), std::next(first, lastIdx));
}

int main(int argc, char const *argv[])
{
    std::vector<int> vector;
    std::cout << "Enter an INT array: ";
    std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), std::back_inserter(vector));

    reverse_array(vector.begin(), vector.end());

    std::cout << "Reversed vector: ";
    std::copy(vector.begin(), vector.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}