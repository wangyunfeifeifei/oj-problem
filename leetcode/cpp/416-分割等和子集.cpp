/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = 0;
    int n = nums.size();
    if (n < 2) return false;
    int m = 0;
    for (int x : nums) {
      sum += x;
      if (x > m) m = x;
    }

    if (sum % 2 != 0) return false;
    sum /= 2;
    if (m > sum) return false;  // 最大的一个值比总和一半大，无法分割
    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
    for (int i = 0; i < n; i++) {
      dp[i][0] = true;
    }
    dp[0][nums[0]] = true;
    for (int i = 1; i < n; i++) {
      int num = nums[i];
      for (int j = 1; j <= sum; j++) {
        if (j >= num)
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - num];
        else
          dp[i][j] = dp[i - 1][j];
      }
    }
    return dp[n - 1][sum];
  }
};
// @lc code=end
