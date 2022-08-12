/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    can = candidates;
    sort(can.begin(), can.end());
    dfs(0, target, false);
    return ans;
  }

 private:
  void dfs(int i, int target, bool usedPre) {
    int n = can.size();
    if (target == 0) {
      ans.push_back(t);
      return;
    }
    if (i == n || target < 0) return;
    dfs(i + 1, target, false);
    if (!usedPre && i > 0 && can[i - 1] == can[i]) {
      return;
    }
    t.push_back(can[i]);
    dfs(i + 1, target - can[i], true);
    t.pop_back();
  }

 private:
  vector<int> can;
  vector<vector<int>> ans;
  vector<int> t;
};
// @lc code=end
