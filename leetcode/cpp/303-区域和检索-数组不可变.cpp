/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

#include "include/headers.h"

// @lc code=start
class NumArray {
 public:
  NumArray(vector<int>& nums) {
    prefix = vector<int>(nums.size());
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      prefix[i] = sum;
    }
  }

  int sumRange(int left, int right) {
    return left == 0 ? prefix[right] : prefix[right] - prefix[left - 1];
  }

 private:
  vector<int> prefix;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
