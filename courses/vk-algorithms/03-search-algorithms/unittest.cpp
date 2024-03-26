#include "gtest/gtest.h"

#include "01-very-simple-task.hpp"
#include "02-is-subsequence.hpp"
#include "03-binary-search-sqrt.hpp"
#include "04-is-palindrome.hpp"
#include "05-remove-duplicates.hpp"


TEST(very_simple_task, normal)
{
    EXPECT_EQ(4, copy_time(5, 1, 2));
    EXPECT_EQ(10, copy_time(10, 1, 20));
    EXPECT_EQ(2, copy_time(3, 1, 1));
}

TEST(is_subsequence_queue, char_array)
{
    EXPECT_TRUE(is_subsequence_queue("abc", "aabbcc"));
    EXPECT_TRUE(is_subsequence_queue("dhwel", "dhwel"));
    EXPECT_TRUE(is_subsequence_queue("", ""));
    EXPECT_FALSE(is_subsequence_queue("asd", "ass"));
    EXPECT_FALSE(is_subsequence_queue("123", "321"));
    EXPECT_FALSE(is_subsequence_queue("brainfuck", "programming language"));
}

TEST(is_subsequence_two_pointers, char_array)
{
    EXPECT_TRUE(is_subsequence_two_pointers("abc", "aabbcc"));
    EXPECT_TRUE(is_subsequence_two_pointers("dhwel", "dhwel"));
    EXPECT_TRUE(is_subsequence_two_pointers("", ""));
    EXPECT_FALSE(is_subsequence_two_pointers("asd", "ass"));
    EXPECT_FALSE(is_subsequence_two_pointers("123", "321"));
    EXPECT_FALSE(is_subsequence_two_pointers("brainfuck", "programming language"));
}

TEST(binary_search_sqrt, positive)
{
    EXPECT_EQ(5, binary_search_sqrt(25));
    EXPECT_EQ(2, binary_search_sqrt(4));
    EXPECT_EQ(3, binary_search_sqrt(10));
}

TEST(is_palindrome_stack, char_array)
{
    EXPECT_TRUE(is_palindrome_stack("ABCBA"));
    EXPECT_TRUE(is_palindrome_stack("qwertyuioppoiuytrewq"));
    EXPECT_TRUE(is_palindrome_stack("a"));
    EXPECT_TRUE(is_palindrome_stack("Yes, it's time!emit s'ti ,seY"));
    EXPECT_FALSE(is_palindrome_stack("No, it isn't."));
    EXPECT_FALSE(is_palindrome_stack("Wanna learn C++?"));
    EXPECT_FALSE(is_palindrome_stack("C++D++E++"));
}

TEST(is_palindrome_two_pointers, char_array)
{
    EXPECT_TRUE(is_palindrome_two_pointers("ABCBA"));
    EXPECT_TRUE(is_palindrome_two_pointers("qwertyuioppoiuytrewq"));
    EXPECT_TRUE(is_palindrome_two_pointers("a"));
    EXPECT_TRUE(is_palindrome_two_pointers("Yes, it's time!emit s'ti ,seY"));
    EXPECT_FALSE(is_palindrome_two_pointers("No, it isn't."));
    EXPECT_FALSE(is_palindrome_two_pointers("Wanna learn C++?"));
    EXPECT_FALSE(is_palindrome_two_pointers("C++D++E++"));
}

TEST(remove_duplicates, char_array)
{
    EXPECT_EQ("c", remove_duplicates("cdffd"));
    EXPECT_EQ("uiui", remove_duplicates("uioouiouuo"));
    EXPECT_EQ("", remove_duplicates("fggfhtyyth"));
    EXPECT_EQ("heoworld", remove_duplicates("hello  world"));
}

int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}