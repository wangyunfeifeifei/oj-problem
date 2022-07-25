/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

#include "include/headers.h"

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  bool isSymmetric(TreeNode* root) {
    if (root == nullptr) return true;
    return isSymmetric(root->left, root->right);
  }

 private:
  bool isSymmetric(TreeNode* left, TreeNode* right) {
    if (left == nullptr && right == nullptr) return true;
    if (left == nullptr || right == nullptr) return false;
    return left->val == right->val && isSymmetric(left->left, right->right) &&
           isSymmetric(left->right, right->left);
  }
};
// @lc code=end
