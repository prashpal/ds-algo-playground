#pragma once
#include <iostream>

struct TreeNode {
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int in_val): val(in_val), left(nullptr), right(nullptr) {}
    TreeNode(int in_val, TreeNode* in_left, TreeNode* in_right): val(in_val), left(in_left), right(in_right) {}
    ~TreeNode() = default;
    int val;
    TreeNode* left;
    TreeNode* right;
};

class TreeAlgorithms {
public:
    int maxDepth(TreeNode* root); // 104 - https://leetcode.com/problems/maximum-depth-of-binary-tree/description/ 
    int goodNodes(TreeNode* root); // 1448 - https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/
};