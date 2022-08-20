/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return constructMaximumBinaryTree(nums, 0, nums.size() - 1);
  }

 private:
  TreeNode* constructMaximumBinaryTree(vector<int>& nums, int i, int j) {
    if (i > j) return nullptr;
    auto t = max_element(nums.begin() + i, nums.begin() + j + 1);
    int idx = t - nums.begin();
    auto ret = new TreeNode(*t);
    ret->left = constructMaximumBinaryTree(nums, i, idx - 1);
    ret->right = constructMaximumBinaryTree(nums, idx + 1, j);
    return ret;
  }
};
// @lc code=end
