#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>


int main(int argc, char const *argv[])
{
    size_t n;
    std::cin >> n;
    std::vector<long long> a(n, 0);
    for (size_t i = 0; i < n; ++i)
        std::cin >> a[i];
    std::transform(a.cbegin(), a.cend(), a.begin(), [](long long val){ return std::abs(val); });

    if (n < 2)
        return 0;

    for (size_t i = 0; i < n; ++i)
    {
        if (i == 0)
            while (a[i] % 2 == 0)
            {
                std::cout << "+";
                ++i;
            }
        if ((a[i] % 2 == 1) && (i > 0))
            std::cout << 'x';
        else if ((a[i] % 2 == 0) && (i < n - 1))
            for (size_t cntr = 0; i + cntr < n; ++cntr)
            {
                if (a[i + cntr] % 2 == 1)
                {
                    std::cout << std::string(cntr, 'x') << '+';
                    i += cntr;
                    break;
                } 
                if (i + cntr == n - 1)
                    std::cout << std::string(cntr, '+');
            }
    }

    return 0;
}