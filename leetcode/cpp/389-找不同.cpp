/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  char findTheDifference(string s, string t) {
    int cnts[26] = {0};
    int cntt[26] = {0};
    for (char ch : s) cnts[ch - 'a']++;
    for (char ch : t) cntt[ch - 'a']++;
    for (int i = 0; i < 26; i++) {
      if (cnts[i] != cntt[i]) return 'a' + i;
    }
    return 'a';
  }
};
// @lc code=end
