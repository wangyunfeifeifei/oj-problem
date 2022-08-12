/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    dfs(digits, 0);
    return ans;
  }
  void dfs(string &digits, int i) {
    int n = digits.size();
    if (n == 0) return;
    if (i == n) {
      ans.push_back(t);
      return;
    }
    int idx = digits[i] - '0';
    for (int k = 0; k < table[idx].size(); k++) {
      t.push_back(table[idx][k]);
      dfs(digits, i + 1);
      t.pop_back();
    }
  }

 private:
  vector<string> ans;
  string t;
  vector<string> table{"",    "",    "abc",  "def", "ghi",
                       "jkl", "mno", "pqrs", "tuv", "wxyz"};
};
// @lc code=end
