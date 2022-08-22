/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  int lengthOfLastWord(string s) {
    int ans = 0;
    int i = s.size() - 1;
    while (i >= 0 && s[i] == ' ') i--;
    while (i >= 0 && s[i--] != ' ') ans++;
    return ans;
  }
};
// @lc code=end
