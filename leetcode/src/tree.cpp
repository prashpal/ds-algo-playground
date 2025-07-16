#include "tree.h"
#include <climits>

int BinaryTree::maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    else if (root->left == nullptr && root->right == nullptr) return 1;
    else return (1 + std::max(maxDepth(root->left), maxDepth(root->right)));
}

int goodNodes_helper(TreeNode* current, int max) {
    if (current == nullptr) return 0;
    int count = 0;
    if (current->val >= max) {
        max = current->val;
        count = 1;
    }
    return (count + goodNodes_helper(current->left, max) + goodNodes_helper(current->right, max));
}
int BinaryTree::goodNodes(TreeNode* root) {
    return goodNodes_helper(root, INT_MIN);
}