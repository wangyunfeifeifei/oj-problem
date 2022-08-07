/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    int n = s.size();
    int i = 0;
    vector<int> cnts(26, 0);
    vector<int> cntp(26, 0);
    for (char ch : p) cntp[ch - 'a']++;
    vector<int> ret;
    for (int j = 0; j < n; j++) {
      cnts[s[j] - 'a']++;
      // 当某个字符开始超过p的该字符个数，移动到该字符上一次出现之后
      while (i <= j && cnts[s[j] - 'a'] > cntp[s[j] - 'a']) {
        cnts[s[i++] - 'a']--;
      }
      if (cnts == cntp) ret.push_back(i);
    }
    return ret;
  }
};
// @lc code=end
