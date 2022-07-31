/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int n = nums.size();
    partition(nums, 0, n - 1);
  }

 private:
  vector<int> partition(vector<int>& nums, int l, int r) {
    if (l >= r) return {l, r};
    int i = l, j = r + 1;
    for (int k = l; k < j; k++) {
      if (nums[k] > 1) {
        while (k < j && nums[k] > 1) {
          swap(nums[k], nums[--j]);
        }
      }
      if (nums[k] < 1) {
        swap(nums[k], nums[i++]);
      }
    }
    return {i, j};
  }
};
// @lc code=end
