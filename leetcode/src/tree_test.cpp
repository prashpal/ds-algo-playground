#include <gtest/gtest.h>
#include "tree.h"

TEST(tree, printnode) {
    TreeNode node(5);
    EXPECT_EQ(5, node.getData());
    node.setData(10);
    EXPECT_EQ(10, node.getData());
}

TEST(tree, getsetnode) {
    TreeNode node(5);
    TreeNode left_node(10);
    TreeNode right_node(15);
    node.setLeft(&left_node);
    EXPECT_EQ(10, node.getLeft()->getData());
}
