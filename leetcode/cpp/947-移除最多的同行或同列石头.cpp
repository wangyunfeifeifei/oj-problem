/*
 * @lc app=leetcode.cn id=947 lang=cpp
 *
 * [947] 移除最多的同行或同列石头
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  int removeStones(vector<vector<int>> &stones) {
    int n = stones.size();
    vector<vector<int>> edge(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
          edge[i].push_back(j);
        }
      }
    }
    vector<int> vis(n);
    int num = 0;
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        num++;  // 连通分量数
        dfs(i, edge, vis);
      }
    }
    return n - num;
  }

 private:
  void dfs(int x, vector<vector<int>> &edge, vector<int> &vis) {
    vis[x] = true;
    for (auto &y : edge[x]) {
      if (!vis[y]) {
        dfs(y, edge, vis);
      }
    }
  }
};
// @lc code=end
