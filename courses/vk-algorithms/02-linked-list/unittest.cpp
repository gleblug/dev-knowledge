#include "gtest/gtest.h"

#include "01-has-cycle.hpp"
#include "02-reverse-linked-list.hpp"
#include "03-middle-node.hpp"
#include "04-remove-values.hpp"
#include "05-merge-sorted-lists.hpp"

TEST(has_cycle, linked_list)
{
    SinglyLinkedList<int> sll1{1, 2, 3, 4, 5, 6, 7, 8, 9};
    SinglyLinkedList<int> sll2{1, 2, 3, 4, 5, 6, 7, 8, 9};
    SinglyLinkedList<int> sll3{};

    sll1.at(8)->next = sll1.at(5);

    EXPECT_TRUE(has_cycle(sll1));
    EXPECT_FALSE(has_cycle(sll2));
    EXPECT_FALSE(has_cycle(sll3));
}

TEST(reverse_linked_list, linked_list)
{
    SinglyLinkedList<int> sll{1, 2, 3, 4, 5, 6};
    SinglyLinkedList<int> res{6, 5, 4, 3, 2, 1};
    reverse_linked_list(sll);
    EXPECT_TRUE(res == sll);
}

TEST(middle_node, linked_list)
{
    SinglyLinkedList<int> sll{6, 2, 3};
    EXPECT_EQ(2, middle_node(sll)->data);
}

TEST(remove_values, linked_list)
{
    SinglyLinkedList<int> sll{1, 1, 2, 3, 5, 7, 2, 3, 2};
    SinglyLinkedList<int> res1{1, 1, 3, 5, 7, 3};
    remove_values(sll, 2);
    EXPECT_TRUE(sll == res1);

    SinglyLinkedList<int> res2{5, 7};
    remove_values(sll, 3);
    remove_values(sll, 1);
    EXPECT_TRUE(sll == res2);
}

TEST(merge_sorted_lists, linked_list)
{
    SinglyLinkedList<int> sll1{1, 4, 5, 8, 10};
    SinglyLinkedList<int> sll2{2, 3, 4, 8, 10, 12};
    SinglyLinkedList<int> res{1, 2, 3, 4, 4, 5, 8, 8, 10, 10, 12};
    
    // result will be recorded to first list
    merge_sorted_lists(sll1, std::move(sll2));
    EXPECT_TRUE(sll1 == res);
}

int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}