/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于 K 的子数组
 */
#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int n = nums.size();
    int ans = 0;
    int i = 0, j = 0;
    int pd = 1;
    while (j < n) {
      pd *= nums[j++];
      while (i < j && pd >= k) {
        pd /= nums[i++];
      }
      /*
        这里j已经加过一次了，所以每次新增的序列最后一个为a[j-1]
        1. a[j-1]
        2. a[j-1], a[j-2]
        ...
        j-i. a[j-1], [j-2], ..., a[i]
      */
      ans += j - i;
    }
    return ans;
  }
};
// @lc code=end
