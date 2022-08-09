/*
 * @lc app=leetcode.cn id=1091 lang=cpp
 *
 * [1091] 二进制矩阵中的最短路径
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    const int n = grid.size();
    if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;
    if (n == 1) return 1;
    const int di[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    queue<pair<int, int>> q;
    if (grid[0][0] == 0) {
      q.push({0, 0});
      grid[0][0] = -1;
    }
    int ans = 1;
    while (!q.empty()) {
      int sz = q.size();
      while (sz--) {
        auto [i, j] = q.front();
        q.pop();
        for (int k = 0; k < 8; k++) {
          int ni = i + di[k];
          int nj = j + dj[k];
          if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 0) {
            if (ni == n - 1 && nj == n - 1) return ans + 1;
            grid[ni][nj] = -1;
            q.push({ni, nj});
          }
        }
      }
      ans++;
    }
    return -1;
  }
};
// @lc code=end
