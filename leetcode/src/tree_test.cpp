#include <gtest/gtest.h>
#include "tree.h"

TreeNode* createTree(const std::vector<int>& values) {
    if (values.empty()) return nullptr;
    std::vector<TreeNode*> nodes;
    for (int val : values) {
        nodes.push_back(val == -1 ? nullptr : new TreeNode(val));
    }
    for (size_t i = 0, j = 1; j < nodes.size(); ++i) {
        if (nodes[i]) {
            if (j < nodes.size()) nodes[i]->left = nodes[j++];
            if (j < nodes.size()) nodes[i]->right = nodes[j++];
        }
    }
    return nodes[0];
}

TEST(Tree, MaxDepth) {
    BinaryTree tree;
    TreeNode* root = createTree({1, 2, 3, 4, 5, -1, -1});
    EXPECT_EQ(tree.maxDepth(root), 3);

    root = createTree({1, 2, -1, 3});
    EXPECT_EQ(tree.maxDepth(root), 3);

    root = createTree({});
    EXPECT_EQ(tree.maxDepth(root), 0);

    root = createTree({1});
    EXPECT_EQ(tree.maxDepth(root), 1);
}

TEST(Tree, GoodNodes) {
    BinaryTree tree;
    TreeNode* root = createTree({3, 1, 4, 3, -1, 1, 5});
    EXPECT_EQ(tree.goodNodes(root), 4);

    root = createTree({3, 3, -1, 4, 2});
    EXPECT_EQ(tree.goodNodes(root), 3);

    root = createTree({1});
    EXPECT_EQ(tree.goodNodes(root), 1);

    root = createTree({});
    EXPECT_EQ(tree.goodNodes(root), 0);
}

