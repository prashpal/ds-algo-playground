#include "tree.h"
#include <climits>

// 104 - https://leetcode.com/problems/maximum-depth-of-binary-tree/description/ 
int TreeAlgorithms::maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    else if (root->left == nullptr && root->right == nullptr) return 1;
    else return (1 + std::max(maxDepth(root->left), maxDepth(root->right)));
}

// 1448 - https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/
int goodNodes_helper(TreeNode* current, int max) {
    if (current == nullptr) return 0;
    int count = 0;
    if (current->val >= max) {
        max = current->val;
        count = 1;
    }
    return (count + goodNodes_helper(current->left, max) + goodNodes_helper(current->right, max));
}
int TreeAlgorithms::goodNodes(TreeNode* root) {
    return goodNodes_helper(root, INT_MIN);
}