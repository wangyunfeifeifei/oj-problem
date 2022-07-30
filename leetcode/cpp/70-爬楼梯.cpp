/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
 public:
  int climbStairs(int n) {
    // f(n) = f(n-1) + f(n-2)
    int a = 0, b = 1, c;
    for (int i = 0; i < n; i++) {
      c = a + b;
      a = b;
      b = c;
    }
    return b;
  }
};
// @lc code=end
