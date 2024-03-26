#pragma once

template <typename T>
inline T binary_search_sqrt(const T target)
{
    T left = 0;
    T right = target;
    while (left <= right)
    {
        T mid = left / 2 + right / 2;
        if (mid * mid > target)
        {
            right = mid - 1;
            continue;
        }
        if (mid * mid < target)
        {
            left = mid + 1;
            continue;
        }
        return mid;
    }
    return right;
}