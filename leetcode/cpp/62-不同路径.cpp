/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  int uniquePaths(int m, int n) {
    vector<int> dp(n, 0);
    dp[0] = 1;
    while (m--) {
      for (int i = 1; i < n; i++) {
        dp[i] = dp[i] + dp[i - 1];
      }
    }
    return dp[n - 1];
  }
};
// @lc code=end
