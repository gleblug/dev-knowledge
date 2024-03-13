#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    unsigned long long n;
    unsigned long long k;
    unsigned d;

    std::cin >> n >> k >> d;
    for (unsigned j = 0; j < 10; ++j)
    {
        if ((n * 10 + j) % k == 0)
        {
            n = n * 10 + j;
            break;
        }
        else if (j == 9) 
        {
            std::cout << -1;
            return 0;
        }
    }

    std::cout << n << std::string(d - 1, '0');
    return 0;
}