/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  int countSegments(string s) {
    int n = s.size();
    int ans = 0;
    int i = 0, j = 0;
    while (true) {
      while (i < n && s[i] == ' ') i++;
      if (i >= n) break;
      ans++;
      int j = i;
      while (j < n && s[j] != ' ') j++;
      i = j;
    }
    return ans;
  }
};
// @lc code=end
