/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  string minWindow(string s, string t) {
    // 抄题解
    for (const char &ch : t) {
      ++mt[ch];
    }
    int l = 0, r = 0;
    int ansL = -1, len = INT_MAX;

    while (r < s.size()) {
      if (mt.count(s[r]) != 0) {
        ++ms[s[r]];
      }
      while (ok() && l <= r) {
        if (r - l + 1 < len) {
          len = r - l + 1;
          ansL = l;
        }
        if (mt.count(s[l]) != 0) {
          --ms[s[l]];
        }
        ++l;
      }
      ++r;
    }

    return ansL == -1 ? "" : s.substr(ansL, len);
  }

 private:
  map<char, int> mt, ms;

 private:
  bool ok() {
    for (const auto &p : mt) {
      if (ms[p.first] < p.second) {  // 没覆盖全
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
