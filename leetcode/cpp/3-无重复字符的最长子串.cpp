/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int l = 0;
    unordered_map<int, int> m;
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (m.count(s[i]) > 0 && m[s[i]] >= l) {
        l = m[s[i]] + 1;
      }
      m[s[i]] = i;
      int len = i - l + 1;
      ans = max(len, ans);
    }
    return ans;
  }
};
// @lc code=end
