/*
 * @lc app=leetcode.cn id=396 lang=cpp
 *
 * [396] 旋转函数
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  int maxRotateFunction(vector<int>& nums) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int ans = 0;
    int F = 0;
    // 计算F0
    for (int i = 0; i < n; i++) {
      F += i * nums[i];
    }
    ans = F;
    for (int i = n - 1; i >= 0; i--) {
      F = F + sum - n * nums[i];
      if (F > ans) ans = F;
    }
    return ans;
  }
};
// @lc code=end
