/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int n = numbers.size();
    int l = 0, r = n - 1;
    while (l < r) {
      int sum = numbers[l] + numbers[r];
      if (sum > target) {
        r--;
      } else if (sum < target) {
        l++;
      } else {
        return {l + 1, r + 1};
      }
    }
    return {-1, -1};
  }
};
// @lc code=end
