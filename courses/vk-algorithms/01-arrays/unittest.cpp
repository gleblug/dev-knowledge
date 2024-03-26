#include <iterator>
#include "gtest/gtest.h"

#include "01-reverse-array.hpp"
#include "02-merge-sort-arrays.hpp"
#include "03-sort-by-odd.hpp"
#include "04-zeros-at-the-end.hpp"

TEST(reverse_array, positive)
{
    std::vector<int> vec{1, 2, 3, 4, 5, 6};
    std::vector<int> res{6, 5, 4, 3, 2, 1};
    reverse_array(vec.begin(), vec.end());
    EXPECT_EQ(vec, res);

    vec = {5, 2};
    res = {2, 5};
    reverse_array(vec.begin(), vec.end());
    EXPECT_EQ(vec, res);
}

TEST(reverse_array, edge_case)
{
    std::vector<int> vec{};
    std::vector<int> res{};
    reverse_array(vec.begin(), vec.end());
    EXPECT_EQ(vec, res);

    vec = {0};
    res = {0};
    reverse_array(vec.begin(), vec.end());
    EXPECT_EQ(vec, res);
}

TEST(reverse_part_of_array, positive)
{
    size_t k = 4;   //               v 4th element
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7};
    std::vector<int> res{5, 6, 7, 1, 2, 3, 4};
    reverse_part_of_array(vec.begin(), vec.end(), k);
    EXPECT_EQ(vec, res);

    k = 0;
    vec = {1, 2, 3, 4, 5, 6, 7};
    res = {1, 2, 3, 4, 5, 6, 7};
    reverse_part_of_array(vec.begin(), vec.end(), k);
    EXPECT_EQ(vec, res);
}

TEST(reverse_part_of_array, edge_case)
{
    size_t k = 2;
    std::vector<int> vec{};
    std::vector<int> res{};
    reverse_part_of_array(vec.begin(), vec.end(), k);
    EXPECT_EQ(vec, res);
}

TEST(merge_sort_arrays, positive)
{
    std::vector<int> vec1{1, 2, 3, 4, 5};
    std::vector<int> vec2{3, 4, 6, 8};    
    std::vector<int> out {};    
    std::vector<int> res {1, 2, 3, 3, 4, 4, 5, 6, 8};

    merge_sort_arrays(vec1.cbegin(), vec1.cend(), vec2.cbegin(), vec2.cend(), std::back_inserter(out));
    EXPECT_EQ(out, res);
}

TEST(merge_sort_arrays, edge_case)
{
    std::vector<int> vec1{};
    std::vector<int> vec2{};    
    std::vector<int> out {};    
    std::vector<int> res {};

    merge_sort_arrays(vec1.cbegin(), vec1.cend(), vec2.cbegin(), vec2.cend(), std::back_inserter(out));
    EXPECT_EQ(out, res);
}

TEST(merge_sort_arrays_optimized, positive)
{
    std::vector<int> vec1{1, 2, 3, 4, 5};
    std::vector<int> vec2{3, 4, 6, 8};    
    std::vector<int> res {1, 2, 3, 3, 4, 4, 5, 6, 8};

    merge_sort_arrays_optimized(vec1, vec2);
    EXPECT_EQ(vec1, res);
}

TEST(sort_by_odd, positive)
{
    std::vector<int> vec{3, 2, 4, 1, 11, 8, 9};
    std::vector<int> res{2, 4, 8, 1, 11, 3, 9};

    sort_by_odd(vec.begin(), vec.end());
    EXPECT_EQ(vec, res);
}

TEST(zeros_at_the_end, positive)
{
    std::vector<int> vec = {0, 0, 1, 0, 3, 12};
    std::vector<int> res = {1, 3, 12, 0, 0, 0};
    zeros_at_the_end(vec.begin(), vec.end());
    EXPECT_EQ(vec, res);

    vec = {0, 33, 57, 88, 60, 0, 0, 80, 99};
    res = {33, 57, 88, 60, 80, 99, 0, 0, 0};
    zeros_at_the_end(vec.begin(), vec.end());
    EXPECT_EQ(vec, res);

    vec = {0, 0, 0, 18, 16, 0, 0, 77, 99};
    res = {18, 16, 77, 99, 0, 0, 0, 0, 0};
    zeros_at_the_end(vec.begin(), vec.end());
    EXPECT_EQ(vec, res);
}

TEST(zeros_at_the_end, edge_case)
{
    std::vector<int> vec = {};
    std::vector<int> res = {};
    zeros_at_the_end(vec.begin(), vec.end());
    EXPECT_EQ(vec, res);

    vec = {0, 0, 0, 0, 0, 0, 0};
    res = {0, 0, 0, 0, 0, 0, 0};
    zeros_at_the_end(vec.begin(), vec.end());
    EXPECT_EQ(vec, res);
}

int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}