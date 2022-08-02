/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int i = 0, j = -1;
    int sum = 0;
    int ans = INT_MAX;
    while (j < n) {
      if (sum < target) {
        j++;
        if (j == n) break;
        sum += nums[j];
        if (sum >= target && j >= i) ans = min(ans, j - i + 1);
      } else {
        sum -= nums[i];
        i++;
        if (sum >= target && j >= i) ans = min(ans, j - i + 1);
      }
    }
    return ans == INT_MAX ? 0 : ans;
  }
};
// @lc code=end
