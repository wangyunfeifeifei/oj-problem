/*
 * @lc app=leetcode.cn id=1161 lang=cpp
 *
 * [1161] 最大层内元素和
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
  int maxLevelSum(TreeNode* root) {
    if (root == nullptr) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int level = 0;
    int maxSum = INT_MIN;
    int maxLevel = 0;
    while (!q.empty()) {
      queue<TreeNode*> tmp;
      level++;
      int sum = 0;
      while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node->left != nullptr) tmp.push(node->left);
        if (node->right != nullptr) tmp.push(node->right);
        sum += node->val;
      }
      if (sum > maxSum) {
        maxSum = sum;
        maxLevel = level;
      }
      q = tmp;
    }
    return maxLevel;
  }
};
// @lc code=end
