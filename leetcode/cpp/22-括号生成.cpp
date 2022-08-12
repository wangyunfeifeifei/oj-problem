/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    if (n == 0) return {};
    dfs(n, n);
    return ans;
  }

 private:
  void dfs(int l, int r) {
    if (l == 0 && r == 0) {
      ans.push_back(t);
      return;
    }
    if (l > 0) {
      t.push_back('(');
      dfs(l - 1, r);
      t.pop_back();
    }
    if (r > l) {
      t.push_back(')');
      dfs(l, r - 1);
      t.pop_back();
    }
  }

 private:
  vector<string> ans;
  string t;
};
// @lc code=end
