/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int last = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (i <= last) {
        last = max(i + nums[i], last);
      } else
        return false;
    }
    return true;
  }
};
// @lc code=end
