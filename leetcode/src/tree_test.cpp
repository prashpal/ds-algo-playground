#include <gtest/gtest.h>
#include "tree.h"

using int_node = Node<int>;

TEST(tree, printnode) {
    int_node node(5);
    EXPECT_EQ(5, node.getData());
    node.setData(10);
    EXPECT_EQ(10, node.getData());
}

TEST(tree, getsetnode) {
    int_node node1(5);
    auto node2_ptr = std::make_unique<int_node>(10);
    node1.setLeft(std::move(node2_ptr));
    EXPECT_EQ(10, node1.getLeft()->getData());
}
