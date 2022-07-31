/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int i = 0;
    for (int j = 0; j < nums.size(); j++) {
      if (nums[j] != val) {
        swap(nums[j], nums[i++]);
      }
    }
    nums.erase(nums.begin() + i, nums.end());
    return i;
  }
};
// @lc code=end
