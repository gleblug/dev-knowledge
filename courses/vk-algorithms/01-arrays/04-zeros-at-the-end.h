#include <array>
#include <iterator>

template <typename InputIt>
inline void zeros_at_the_end(const InputIt first, const InputIt last)
{
    if (first == last)
        return;

    auto zeroIt = first;
    auto numIt = first;
    while (numIt < last && zeroIt < last)
    {
        if (*zeroIt == 0 && *numIt != 0)
            std::swap(*zeroIt, *numIt);
        while (*zeroIt != 0 && zeroIt != last)
            ++zeroIt;
        while (*numIt == 0 && numIt != last)
            ++numIt;
    }
}