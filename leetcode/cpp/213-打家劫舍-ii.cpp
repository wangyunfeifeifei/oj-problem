/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0)
      return 0;
    else if (n == 1)
      return nums[0];
    return max(doRob(nums, 0, n - 2), doRob(nums, 1, n - 1));
  }

 private:
  int doRob(vector<int>& nums, int s, int e) {
    if (s == e) return nums[s];
    int a = nums[s], b = max(nums[s], nums[s + 1]);
    for (int i = s + 2; i <= e; i++) {
      int t = b;
      b = max(nums[i] + a, b);
      a = t;
    }
    return b;
  }
};
// @lc code=end
