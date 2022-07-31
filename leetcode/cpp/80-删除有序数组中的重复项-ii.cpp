/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int i = 0;
    int time = 1;
    for (int j = 1; j < nums.size(); j++) {
      if (nums[j] > nums[i]) {
        nums[++i] = nums[j];
        time = 1;
      } else if (nums[j] == nums[i] && time < 2) {
        nums[++i] = nums[j];
        time++;
      } else {
        continue;
      }
    }
    return i + 1;
  }
};
// @lc code=end
