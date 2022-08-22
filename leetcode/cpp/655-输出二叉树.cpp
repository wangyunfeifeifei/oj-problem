/*
 * @lc app=leetcode.cn id=655 lang=cpp
 *
 * [655] 输出二叉树
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
  vector<vector<string>> printTree(TreeNode* root) {
    size_t m = height(root);
    size_t n = (1 << m) - 1;
    auto ret = vector<vector<string>>(m, vector<string>(n));
    fill(root, ret, 0, n / 2);
    return ret;
  }

 private:
  size_t height(TreeNode* root) {
    if (root == nullptr) return 0;
    return max(height(root->left), height(root->right)) + 1;
  }
  void fill(TreeNode* root, vector<vector<string>>& ret, int i, int j) {
    int m = ret.size();
    int n = ret[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n) return;
    ret[i][j] = to_string(root->val);
    if (i == m - 1) return;
    if (root->left != nullptr) {
      fill(root->left, ret, i + 1, j - (1 << (m - i - 2)));
    }
    if (root->right != nullptr) {
      fill(root->right, ret, i + 1, j + (1 << (m - i - 2)));
    }
  }
};
// @lc code=end
