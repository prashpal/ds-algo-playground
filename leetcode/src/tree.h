#pragma once
#include <iostream>
#include <memory>

class TreeNode {
public:
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int in_val): val(in_val), left(nullptr), right(nullptr) {}
    TreeNode(int in_val, TreeNode* in_left, TreeNode* in_right): val(in_val), left(in_left), right(in_right) {}
    ~TreeNode() = default;

    int getData() const {
        return this->val;
    }
    TreeNode* getLeft() const {
        return this->left;
    }
    TreeNode* getRight() const {
        return this->right;
    }
    void setData(int in_val) {
        val = in_val;
    }
    void setLeft(TreeNode* in_left) {
        this->left = in_left;
    }
    void setRight(TreeNode* in_right) {
        this->right = in_right;
    }
private:
    int val;
    TreeNode* left;
    TreeNode* right;
};

class BinaryTree {
public:
    BinaryTree() = delete;
    BinaryTree(TreeNode in_root): root(in_root) {}
private:
    TreeNode root;
};