/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<int> cur;
    dfs(graph, 0, cur);
    return ans;
  }

 private:
  void dfs(vector<vector<int>>& graph, int i, vector<int>& cur) {
    int n = graph.size();
    cur.push_back(i);
    if (i == n - 1) {
      ans.push_back(cur);
      cur.pop_back();
      return;
    }
    for (int node : graph[i]) {
      dfs(graph, node, cur);
    }
    cur.pop_back();
  }

 private:
  vector<vector<int>> ans;
};
// @lc code=end
