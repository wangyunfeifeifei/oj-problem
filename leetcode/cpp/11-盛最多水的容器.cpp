/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  int maxArea(vector<int>& height) {
    int n = height.size();
    int i = 0, j = n - 1;
    int maxArea = INT_MIN;
    while (i < j) {
      int area = (j - i) * min(height[i], height[j]);
      maxArea = max(area, maxArea);
      if (height[i] > height[j])
        j--;
      else
        i++;
    }
    return maxArea;
  }
};
// @lc code=end
