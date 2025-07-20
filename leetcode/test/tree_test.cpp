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

// 104 - https://leetcode.com/problems/maximum-depth-of-binary-tree/description/ 
TEST(Tree, MaxDepth) {
    TreeAlgorithms treeAlgo;
    TreeNode* root = createTree({1, 2, 3, 4, 5, -1, -1});
    EXPECT_EQ(treeAlgo.maxDepth(root), 3);

    root = createTree({1, 2, -1, 3});
    EXPECT_EQ(treeAlgo.maxDepth(root), 3);

    root = createTree({});
    EXPECT_EQ(treeAlgo.maxDepth(root), 0);

    root = createTree({1});
    EXPECT_EQ(treeAlgo.maxDepth(root), 1);
}

// 1448 - https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/
TEST(Tree, GoodNodes) {
    TreeAlgorithms treeAlgo;
    TreeNode* root = createTree({3, 1, 4, 3, -1, 1, 5});
    EXPECT_EQ(treeAlgo.goodNodes(root), 4);

    root = createTree({3, 3, -1, 4, 2});
    EXPECT_EQ(treeAlgo.goodNodes(root), 3);

    root = createTree({1});
    EXPECT_EQ(treeAlgo.goodNodes(root), 1);

    root = createTree({});
    EXPECT_EQ(treeAlgo.goodNodes(root), 0);
}

