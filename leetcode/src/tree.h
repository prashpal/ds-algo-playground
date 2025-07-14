#pragma once
#include <iostream>
#include <memory>

struct TreeNode {
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int in_val): val(in_val), left(nullptr), right(nullptr) {}
    TreeNode(int in_val, TreeNode* in_left, TreeNode* in_right): val(in_val), left(in_left), right(in_right) {}
    ~TreeNode() = default;
    int val;
    TreeNode* left;
    TreeNode* right;
};

class BinaryTree {
public:
    // https://leetcode.com/problems/maximum-depth-of-binary-tree/description/ 
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        else if (root->left == nullptr && root->right == nullptr) return 1;
        else if (root->left != nullptr && root->right == nullptr) return (1 + maxDepth(root->left));
        else if (root->left == nullptr && root->right != nullptr) return (1 + maxDepth(root->right)); 
        else return (1 + std::max(maxDepth(root->left), maxDepth(root->right)));
    }
};