/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  string longestPalindrome(string s) {
    string ret;
    int n = s.size();
    deque<char> dq;
    for (int i = 0; i < n; i++) {
      string t = spread(s, i);
      if (t.size() > ret.size()) ret = t;
    }
    return ret;
  }

 private:
  string spread(string &s, int i) {
    int n = s.size();
    deque<char> dq1;
    deque<char> dq2;
    dq1.push_back(s[i]);
    for (int l = i - 1, r = i + 1; l >= 0 && r < n && s[l] == s[r]; l--, r++) {
      dq1.push_front(s[l]);
      dq1.push_back(s[r]);
    }
    for (int l = i, r = i + 1; l >= 0 && r < n && s[l] == s[r]; l--, r++) {
      dq2.push_front(s[l]);
      dq2.push_back(s[r]);
    }
    string ret;
    if (dq1.size() > dq2.size()) {
      ret = string(dq1.begin(), dq1.end());
    } else {
      ret = string(dq2.begin(), dq2.end());
    }
    return ret;
  }
};
// @lc code=end
