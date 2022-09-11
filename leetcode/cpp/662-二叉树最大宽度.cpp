/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
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
  int widthOfBinaryTree(TreeNode* root) {
    if (root == nullptr) return 0;
    queue<pair<TreeNode*, unsigned long long>> qu;
    qu.emplace(root, 1);
    unsigned long long ans = 0;
    while (!qu.empty()) {
      int sz = qu.size();
      unsigned long long left = 0, right;
      while (sz--) {
        auto [node, pos] = qu.front();
        qu.pop();
        if (node->left != nullptr) qu.emplace(node->left, pos * 2);
        if (node->right != nullptr) qu.emplace(node->right, pos * 2 + 1);
        if (left == 0) left = pos;
        right = pos;
      }
      unsigned long long dis = right - left + 1;
      ans = max(dis, ans);
    }

    return ans;
  }
};
// @lc code=end
