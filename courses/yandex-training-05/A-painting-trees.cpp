#include <iostream>
#include <utility>


template <typename T>
std::size_t len_of_intersection(std::pair<T, T> seg1, std::pair<T, T> seg2)
{
    if (seg1.second < seg2.first || seg1.first > seg2.second) // intersection is empty
        return 0;

    if (seg1.first < seg2.first && seg1.second < seg2.second)
        return seg1.second - seg2.first + 1;
    
    if (seg1.second > seg2.second && seg1.first > seg2.first)
        return seg2.second - seg1.first + 1;

    return std::min(seg1.second - seg1.first, seg2.second - seg2.first) + 1; // one segment is nested
}

int main(int argc, char const *argv[])
{
    long long p, v;
    std::cin >> p >> v;
    long long q, m;
    std::cin >> q >> m;

    auto segv = std::make_pair(p - v, p + v);
    auto segm = std::make_pair(q - m, q + m);

    std::size_t answer = 2 * (v + m + 1) - len_of_intersection(segv, segm);
    std::cout << answer;

    return 0;
}