#pragma once
#include <algorithm>
#include <ctime>


inline time_t copy_time(std::size_t n, time_t x, time_t y)
{
    time_t left = 0;
    time_t right = (n - 1) * std::max(x, y);

    while (left + 1 < right)
    {
        auto mid = left / 2 + right / 2;
        if ((mid / x) + (mid / y) < (n - 1))
            left = mid;
        else
        right = mid;
    }

    return right + std::min(x, y);

}