#include <cstddef>
#include <iostream>
#include <bitset>


void possible_horse_ways(int i, int j, char field[8][8])
{
    for (int step_i : {-2, -1, 1, 2})
        for (int step_j : {3 - std::abs(step_i), - 3 + std::abs(step_i)})
        {
            int new_i = i + step_i;
            int new_j = j + step_j;
            if (new_i >= 0 && new_i < 8 
                && new_j >= 0 && new_j < 8)
                field[new_i][new_j] = '%';
        }
}

void possible_bishop_ways(int i, int j, char field[8][8])
{
    for (int dir = 0; dir < 4; ++dir)
        for (int step = 1; step < 8; ++step)
        {
            int new_i = i + (static_cast<int>(std::bitset<2>(dir)[0]) * 2 - 1) * step;
            int new_j = j + (static_cast<int>(std::bitset<2>(dir)[1]) * 2 - 1) * step;
            if (new_i >= 0 && new_i < 8 
                && new_j >= 0 && new_j < 8
                && (field[new_i][new_j] == '*' || field[new_i][new_j] == '%'))
                field[new_i][new_j] = '%';
            else
                break;
        }
}

void possible_rook_ways(int i, int j, char field[8][8])
{
    for (int dir = 0; dir < 4; ++dir)
        for (int step = 1; step < 8; ++step)
        {
            int new_i = i + (dir % 2) * (dir % 4 - 2) * step;
            int new_j = j + ((dir + 1) % 2) * ((dir + 1) % 4 - 2) * step;
            if (new_i >= 0 && new_i < 8 
                && new_j >= 0 && new_j < 8
                && (field[new_i][new_j] == '*' || field[new_i][new_j] == '%'))
                field[new_i][new_j] = '%';
            else
                break;
        }
}

int main(int argc, char const *argv[])
{
    char field[8][8];
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            std::cin >> field[i][j];

    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
        {
            switch (field[i][j])
            {
                case 'B':
                    possible_bishop_ways(i, j, field);
                    break;
                case 'R':
                    possible_rook_ways(i, j, field);
                    break;
                default:
                    break;
            }
        }

    size_t result = 0;
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            if (field[i][j] != '*')
                ++result;

    std::cout << 64 - result;

    return 0;
}