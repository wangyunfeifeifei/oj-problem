/*
 * @lc app=leetcode.cn id=919 lang=cpp
 *
 * [919] 完全二叉树插入器
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
class CBTInserter {
 public:
  CBTInserter(TreeNode* root) {
    if (root == NULL) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();
      container.push_back(node);
      if (node->left != nullptr) q.push(node->left);
      if (node->right != nullptr) q.push(node->right);
    }
  }

  int insert(int val) {
    int len = container.size();
    if (len == 0) {
      container.push_back(new TreeNode(val));
      return -1;
    } else {
      TreeNode* parent = container[(len - 1) / 2];
      TreeNode* toInsert = new TreeNode(val);
      if (len % 2 != 0)
        parent->left = toInsert;
      else
        parent->right = toInsert;
      container.push_back(toInsert);
      return parent->val;
    }
  }

  TreeNode* get_root() {
    int len = container.size();
    if (len == 0) throw "Tree is empty()";
    return container[0];
  }

 private:
  vector<TreeNode*> container;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
// @lc code=end
