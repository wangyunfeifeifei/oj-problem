/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  string reverseWords(string s) {
    int n = s.size();
    int i = 0;
    while (true) {
      while (i < n && s[i] == ' ') i++;
      int j = i;
      while (j < n && s[j] != ' ') j++;
      if (j > n) break;
      reverse(s.begin() + i, s.begin() + j);
      i = j + 1;
    }
    return s;
  }
};
// @lc code=end
