/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  int rangeBitwiseAnd(int left, int right) {
    if (left == right) return left;
    int k = 31;
    // 找到第一个不相等的位置
    while (k > 0 && (left & (1 << k)) ^ (right & (1 << k)) == 0) k--;
    return (left >> k) << k;
  }
};
// @lc code=end
