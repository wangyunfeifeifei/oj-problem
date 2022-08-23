/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    int cntr[26] = {0};
    int cntm[26] = {0};
    for (char ch : magazine) cntm[ch - 'a']++;
    for (char ch : ransomNote) {
      cntr[ch - 'a']++;
      if (cntr[ch - 'a'] > cntm[ch - 'a']) return false;
    }
    return true;
  }
};
// @lc code=end
