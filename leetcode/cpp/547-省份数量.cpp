/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int m = isConnected.size();
    visited = vector<int>(m, false);
    int ans = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
        if (isConnected[i][j] == 1) {
          ans++;
          dfs(isConnected, i);
        }
      }
    }
    return ans;
  }

 private:
  vector<int> visited;

 private:
  void dfs(vector<vector<int>>& isConnected, int i) {
    if (visited[i]) return;
    visited[i] = true;
    int m = isConnected.size();
    for (int j = 0; j < m; j++) {
      if (isConnected[i][j] == 1) {
        isConnected[i][j] = isConnected[j][i] = 0;
        dfs(isConnected, j);
      }
    }
  }
};
// @lc code=end
