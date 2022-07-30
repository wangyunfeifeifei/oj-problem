/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  int fib(int n) {
    int a = 0, b = 1, c;
    for (int i = 0; i < n; i++) {
      c = a + b;
      a = b;
      b = c;
    }
    return a;
  }
};
// @lc code=end
