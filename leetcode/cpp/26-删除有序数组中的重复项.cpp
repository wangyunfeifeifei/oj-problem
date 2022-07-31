/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int n : nums) {
      if (n > nums[i]) {
        nums[++i] = n;
      }
    }
    ++i;
    nums.erase(nums.begin() + i, nums.end());
    return i;
  }
};
// @lc code=end
