/*
 * @lc app=leetcode.cn id=498 lang=cpp
 *
 * [498] 对角线遍历
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    m = mat.size();
    n = mat[0].size();
    int dirs[2][2] = {{-1, 1}, {1, -1}};
    int k = 0;
    int T = m * n;
    vector<int> ans;
    int x = 0, y = 0;
    for (int i = 0; i < T; i++) {
      ans.push_back(mat[x][y]);
      int nx = x + dirs[k][0];
      int ny = y + dirs[k][1];
      if (valid(nx, ny)) {
        x = nx;
        y = ny;
      } else {
        if (k == 0 && valid(x, y + 1)) {
          y++;
        } else if (k == 0 && valid(x + 1, y)) {
          x++;
        } else if (k == 1 && valid(x + 1, y)) {
          x++;
        } else if (k == 1 && valid(x, y + 1)) {
          y++;
        } else {
          break;
        }
        k = (k + 1) % 2;
      }
    }
    return ans;
  }

 private:
  bool valid(int i, int j) { return i >= 0 && i < m && j >= 0 && j < n; }

 private:
  int m, n;
};
// @lc code=end
