/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  string reverseVowels(string s) {
    int n = s.size();
    int i = 0, j = n - 1;
    while (i < j) {
      if (!isVowels(s[i])) {
        i++;
        continue;
      }
      if (!isVowels(s[j])) {
        j--;
        continue;
      }
      swap(s[i++], s[j--]);
    }
    return s;
  }

 private:
  bool isVowels(char ch) {
    ch = tolower(ch);
    char s[5] = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < 5; i++) {
      if (ch == s[i]) return true;
    }
    return false;
  }
};
// @lc code=end
