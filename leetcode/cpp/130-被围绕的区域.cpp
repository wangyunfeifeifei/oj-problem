/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  void solve(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    queue<pair<int, int>> q;
    // 左右边界的'O'
    for (int i = 0; i < m; i++) {
      if (board[i][0] == 'O') {
        board[i][0] = 'A';
        q.push({i, 0});
      }
      if (board[i][n - 1] == 'O') {
        board[i][n - 1] = 'A';
        q.push({i, n - 1});
      }
    }
    // 上下边界的'O'
    for (int j = 0; j < n; j++) {
      if (board[0][j] == 'O') {
        board[0][j] = 'A';
        q.push({0, j});
      }
      if (board[m - 1][j] == 'O') {
        board[m - 1][j] = 'A';
        q.push({m - 1, j});
      }
    }
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, 1, -1};
    // 标记与边界相连的区域
    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();
      for (int k = 0; k < 4; k++) {
        int ni = i + di[k];
        int nj = j + dj[k];
        if (ni >= 0 && ni < m && nj >= 0 && nj < n && board[ni][nj] == 'O') {
          board[ni][nj] = 'A';
          q.push({ni, nj});
        }
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == 'A') {
          board[i][j] = 'O';
        } else {
          board[i][j] = 'X';
        }
      }
    }
  }
};
// @lc code=end
