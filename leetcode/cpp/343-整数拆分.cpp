/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  int integerBreak(int n) {
    if (n < 4) return n - 1;  // 2 -> 1, 3 -> 2
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    if (n > 2) dp[3] = 3;
    for (int i = 4; i <= n; i++) {
      // 所有的最终都会分为2,3的组合
      // 4 -> 2, 2   5->2, 3    6->3, 3   7->3, 4->3,2,2
      // 8 -> 3, 5 -> 3, 3, 2
      // 9 -> 3, 6 -> 3, 3, 3
      dp[i] = max(dp[i - 2] * 2, dp[i - 3] * 3);
    }
    return dp[n];
  }
};
// @lc code=end
