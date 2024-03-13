#include <iostream>


template <typename T>
T number_of_keys(T a)
{
    T tab = a / 4;
    T space = 0;
    T backspace = 0;

    if (a % 4 == 3) { backspace = 1; tab += 1; }
    else space = a % 4;

    return tab + space + backspace;
}

int main(int argc, char const *argv[])
{
    unsigned long long result = 0;
    uint n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        unsigned long long a;
        std::cin >> a;
        result += number_of_keys(a);
    }

    std::cout << result;

    return 0;
}