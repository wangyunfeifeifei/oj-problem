/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int i = 0;
    for (int j = 0; j < nums.size(); j++) {
      if (nums[j] != 0) {
        swap(nums[j], nums[i++]);
      }
    }
  }
};
// @lc code=end
