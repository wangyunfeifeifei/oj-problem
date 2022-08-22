/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 */
#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  bool detectCapitalUse(string word) {
    bool lower = true;
    bool allupper = true;
    for (int i = 0; i < word.size(); i++) {
      if (islower(word[i])) allupper = false;
      if (i > 0 && isupper(word[i])) lower = false;
    }
    return lower || allupper;
  }
};
// @lc code=end
