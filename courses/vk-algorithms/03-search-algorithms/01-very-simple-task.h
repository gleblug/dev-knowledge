#pragma once
#include <algorithm>
#include <ctime>


inline time_t copy_time(std::size_t n, time_t x, time_t y)
{
    time_t l = 0;
    time_t r = (n - 1) * std::max(x, y);

    while (l + 1 < r)
    {
        auto mid = (l + r) / 2;
        if ((mid / x) + (mid / y) < (n - 1))
            l = mid;
        else
        r = mid;
    }

    return r + std::min(x, y);

}