/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int p = partition(nums, l, r);
      if (p + 1 == k) {
        return nums[p];
      } else if (p + 1 > k) {
        r = p - 1;
      } else {
        l = p + 1;
      }
    }
    return -1;
  }
  int partition(vector<int>& nums, int l, int r) {
    if (l == r) return l;
    int v = nums[l];
    int i = l + 1, j = r;
    while (true) {
      while (j > l && nums[j] <= v) j--;
      while (i < r && nums[i] >= v) i++;
      if (i >= j) break;
      swap(nums[i], nums[j]);
    }
    swap(nums[j], nums[l]);
    return j;
  }
};
// @lc code=end
