/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 颠倒字符串中的单词
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  string reverseWords(string s) {
    int n = s.size();
    int i = 0;
    string ret;
    while (true) {
      string word;
      while (i < n && s[i] == ' ') i++;
      int j = i;
      while (j < n && s[j] != ' ') j++;
      if (j > n || j == i) break;
      word = s.substr(i, j - i);
      reverse(word.begin(), word.end());
      if (ret.empty())
        ret += word;
      else
        ret = ret + " " + word;
      i = j + 1;
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }
};
// @lc code=end
