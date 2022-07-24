/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int minF = 1, maxF = 1, ans = nums[0];
    for (int num : nums) {
      int mn = minF, mx = maxF;
      minF = min(mn * num, min(num * mx, num));
      maxF = max(mx * num, max(mn * num, num));
      ans = max(ans, maxF);
    }
    return ans;
  }
};
// @lc code=end
