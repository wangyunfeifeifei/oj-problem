/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) {
      return;
    }
    int i = n - 2, j = n - 1, k = n - 1;
    for (; i >= 0 && nums[i] >= nums[j]; i--, j--) {  // 找到第一个升序对}
    }
    if (i >= 0) {
      // 不是最后一个排列（全逆序排列）
      while (nums[i] >= nums[k]) k--;  // 找到[j, end)里比nums[i]大的最小的
      swap(nums[i], nums[k]);
    }

    reverse(nums.begin() + j, nums.end());  // 反转[j, end)
  }
};
// @lc code=end
