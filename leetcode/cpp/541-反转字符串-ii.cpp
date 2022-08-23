/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  string reverseStr(string s, int k) {
    int n = s.size();
    int i = 0;
    while (i < n) {
      int end = min(i + k, n);
      reverse(s.begin() + i, s.begin() + end);
      i += 2 * k;
    }
    return s;
  }
};
// @lc code=end
