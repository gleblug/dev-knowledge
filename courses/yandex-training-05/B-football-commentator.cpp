#include <iostream>
#include <string>


int main(int argc, char const *argv[])
{
    std::string input;
    std::cin >> input;
    int g1[2];
    int g2[2];
    g1[0] = std::stoi(input.substr(0, 1));
    g2[0] = std::stoi(input.substr(2, 3));

    std::cin >> input;
    g1[1] = std::stoi(input.substr(0, 1));
    g2[1] = std::stoi(input.substr(2, 3));

    uint home1;
    std::cin >> home1;
    --home1;
    uint home2 = static_cast<uint>(!home1);

    auto delta = g2[0] + g2[1] - g1[0] - g1[1];
    uint result = 0;

    if (delta >= 0)
    {
        g1[1] += delta;
        result = delta;
        if (g1[home2] <= g2[home1]) result += 1;
    }

    std::cout << result;

    return 0;
}