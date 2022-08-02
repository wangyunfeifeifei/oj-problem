/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    int low = -1, high = -1;
    int l = 0, r = n - 1;
    // 找左边界
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] < target) {
        l = mid + 1;
      } else if (nums[mid] > target) {
        r = mid - 1;
      } else {
        if (mid == 0 || nums[mid - 1] != target) {
          low = mid;
          break;
        } else {
          r = mid - 1;
        }
      }
    }
    // 找右边界
    l = 0, r = n - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] < target) {
        l = mid + 1;
      } else if (nums[mid] > target) {
        r = mid - 1;
      } else {
        if (mid == n - 1 || nums[mid + 1] != target) {
          high = mid;
          break;
        } else {
          l = mid + 1;
        }
      }
    }
    return {low, high};
  }
};
// @lc code=end
