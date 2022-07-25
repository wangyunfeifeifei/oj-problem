/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
  vector<int> rightSideView(TreeNode* root) {
    if (root == NULL) return {};
    vector<int> ans;
    queue<TreeNode*> q;
    q.emplace(root);
    while (!q.empty()) {
      queue<TreeNode*> t;
      int k = 0;
      while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node->left) t.push(node->left);
        if (node->right) t.push(node->right);
        k = node->val;
      }
      ans.push_back(k);
      q = t;
    }
    return ans;
  }
};
// @lc code=end
