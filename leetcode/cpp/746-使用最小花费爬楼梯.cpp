/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    int a = cost[0], b = cost[1], c;
    for (int i = 2; i < n; i++) {
      c = cost[i] + min(a, b);
      a = b;
      b = c;
    }
    return min(a, b);
  }
};
// @lc code=end
