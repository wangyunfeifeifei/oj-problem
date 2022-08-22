/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

#include "include/headers.h"

// @lc code=start
class NumMatrix {
 public:
  NumMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    sum = vector<vector<long long>>(m + 1, vector<long long>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        sum[i][j] = matrix[i - 1][j - 1] + sum[i - 1][j] + sum[i][j - 1] -
                    sum[i - 1][j - 1];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    row2++;
    col2++;
    return sum[row2][col2] - sum[row1][col2] - sum[row2][col1] +
           sum[row1][col1];
  }

 private:
  vector<vector<long long>> sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
