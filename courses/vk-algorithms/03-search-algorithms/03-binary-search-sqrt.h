#pragma once
template <typename T>
inline T binary_search_sqrt(const T target)
{
    T l = 0;
    T r = target;
    while (l <= r)
    {
        T mid = (l + r) / 2;
        if (mid * mid > target)
        {
            r = mid - 1;
            continue;
        }
        if (mid * mid < target)
        {
            l = mid + 1;
            continue;
        }
        return mid;
    }
    return r;
}