#include <cstdint>
#include <iterator>
#include <vector>
#include <iostream>


// move all odd numbers to back of array
template <typename InputIt>
void sort_by_odd(InputIt first, InputIt last)
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

int main(int argc, char const *argv[])
{
    std::vector<uint16_t> vec;
    std::copy(std::istream_iterator<uint16_t>(std::cin), std::istream_iterator<uint16_t>(), std::back_inserter(vec));
    sort_by_odd(vec.begin(), vec.end());
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<uint16_t>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}