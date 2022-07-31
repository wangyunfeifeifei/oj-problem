/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    if (m == 0) return 0;
    int n = obstacleGrid[0].size();
    vector<int> dp(n, 0);
    dp[0] = obstacleGrid[0][0] == 1 ? 0 : 1;
    for (int i = 1; i < n; i++) {
      if (obstacleGrid[0][i] == 1)
        dp[i] = 0;
      else
        dp[i] = dp[i - 1];
    }
    for (int i = 1; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (obstacleGrid[i][j] == 1)
          dp[j] = 0;
        else if (j > 0)
          dp[j] = dp[j - 1] + dp[j];
      }
    }
    return dp[n - 1];
  }
};
// @lc code=end
