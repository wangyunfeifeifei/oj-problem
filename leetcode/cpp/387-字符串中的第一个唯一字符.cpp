/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  int firstUniqChar(string s) {
    int cnt[26] = {0};
    for (char ch : s) {
      cnt[ch - 'a']++;
    }
    for (int i = 0; i < s.size(); i++) {
      if (cnt[s[i] - 'a'] == 1) return i;
    }
    return -1;
  }
};
// @lc code=end
