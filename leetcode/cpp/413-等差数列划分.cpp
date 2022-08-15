/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) {
      return 0;
    }

    int d = nums[0] - nums[1], t = 0;
    int ans = 0;
    for (int i = 2; i < n; i++) {
      if (nums[i - 1] - nums[i] == d) {
        ++t;
      } else {
        d = nums[i - 1] - nums[i];
        t = 0;
      }
      ans += t;
    }
    return ans;
  }
};
// @lc code=end
