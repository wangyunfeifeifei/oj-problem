/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    int x = m - 1;
    int y = 0;
    while (matrix[x][y] != target) {
      if (matrix[x][y] > target) {
        if (x == 0) return false;
        x--;
      } else if (matrix[x][y] < target) {
        if (y == n - 1) return false;
        y++;
      }
    }
    return true;
  }
};
// @lc code=end
