/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  bool isPalindrome(string s) {
    int n = s.size();
    int l = 0, r = n - 1;
    while (l < r) {
      while (l < n && !isalpha(s[l]) && !isdigit(s[l])) l++;
      while (r >= 0 && !isalpha(s[r]) && !isdigit(s[r])) r--;
      if (l >= r) break;
      char a = tolower(s[l++]);
      char b = tolower(s[r--]);
      if (a != b) return false;
    }
    return true;
  }
};
// @lc code=end
