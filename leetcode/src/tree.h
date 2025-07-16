#pragma once
#include <iostream>
#include <memory>
#include <climits>

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
        else return (1 + std::max(maxDepth(root->left), maxDepth(root->right)));
    }
    // https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/
    int goodNodes_helper(TreeNode* current, int max) {
        if (current == nullptr) return 0;
        int count = 0;
        if (current->val >= max) {
            max = current->val;
            count = 1;
        }
        return (count + goodNodes_helper(current->left, max) + goodNodes_helper(current->right, max));
    }
    int goodNodes(TreeNode* root) {
        return goodNodes_helper(root, INT_MIN);
    }
};