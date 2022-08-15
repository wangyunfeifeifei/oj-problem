/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  int jump(vector<int>& nums) {
    int n = nums.size();
    int last = 0;
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
      int t = nums[i] + i;
      for (int k = last + 1; k < n && k <= t; k++) {
        dp[k] = min(dp[k], dp[i] + 1);
      }
      last = t;
    }
    return dp[n - 1];
  }
};
// @lc code=end
