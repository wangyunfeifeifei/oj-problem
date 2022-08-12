/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

#include "include/headers.h"

// @lc code=start
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    bd = board;
    wd = word;
    ans = false;
    int m = bd.size();
    int n = bd[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == word[0]) {
          vis[i][j] = true;
          dfs(1, i, j, vis);
          vis[i][j] = false;
        }
      }
    }
    return ans;
  }

 private:
  void dfs(int i, int x, int y, vector<vector<bool>>& visited) {
    if (ans) return;
    if (i == wd.size()) {
      ans = true;
      return;
    }
    int m = bd.size();
    int n = bd[0].size();
    for (int k = 0; k < 4; k++) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      if (nx >= 0 && nx < m && ny >= 0 && ny < n && bd[nx][ny] == wd[i] &&
          !visited[nx][ny]) {
        visited[nx][ny] = true;
        dfs(i + 1, nx, ny, visited);
        visited[nx][ny] = false;
      }
    }
  }

 private:
  vector<vector<char>> bd;
  string wd;
  bool ans;
};
// @lc code=end
