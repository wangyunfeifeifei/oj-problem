/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int n = nums.size();
    int l = 0, r = n - 1;
    int curmin = nums[r];
    while (l < r && nums[l] >= nums[r]) {
      int mid = l + (r - l) / 2;
      if (nums[mid] > curmin) {
        l = mid + 1;
      } else {
        r = mid;
        curmin = nums[r];
      }
    }
    int offset = l;  // 索引为l的值是最小值
    l = 0;
    r = n - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      int pos = (mid + offset) % n;
      if (nums[pos] == target) {
        return pos;
      } else if (nums[pos] < target) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return -1;
  }
};
// @lc code=end
