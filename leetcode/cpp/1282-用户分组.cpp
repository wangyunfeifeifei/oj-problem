/*
 * @lc app=leetcode.cn id=1282 lang=cpp
 *
 * [1282] 用户分组
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < groupSizes.size(); i++) {
      m[groupSizes[i]].push_back(i);
    }
    vector<vector<int>> ans;
    for (auto p : m) {
      vector<int> t;
      int k = 0;
      for (int i : p.second) {
        t.push_back(i);
        k++;
        if (k == p.first) {
          ans.push_back(t);
          t.clear();
          k = 0;
        }
      }
    }
    return ans;
  }
};
// @lc code=end
