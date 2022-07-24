/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

#include "include/display.h"
#include "include/headers.h"

// @lc code=start
const int di[4] = {0, 0, 1, -1};
const int dj[4] = {1, -1, 0, 0};

class Solution {
 public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    // 1 <= m, n <= 200;
    size_t m = heights.size();
    size_t n = heights[0].size();
    vector<vector<bool>> pacific(m, vector<bool>(n, false));   // 太平洋
    vector<vector<bool>> atlantic(m, vector<bool>(n, false));  // 大西洋
    for (int i = 0; i < m; i++) {                              // 第一列
      bfs(i, 0, heights, pacific);
    }
    for (int i = 1; i < n; i++) {  // 第一行
      bfs(0, i, heights, pacific);
    }
    for (int i = 0; i < m; i++) {  // 最后一列
      bfs(i, n - 1, heights, atlantic);
    }
    for (int i = 0; i < n - 1; i++) {  // 最后一行
      bfs(m - 1, i, heights, atlantic);
    }

    vector<vector<int>> ret;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (pacific[i][j] && atlantic[i][j]) {
          ret.push_back({i, j});
        }
      }
    }
    return ret;
  }

 private:
  void bfs(int i, int j, vector<vector<int>> &heights,
           vector<vector<bool>> &ocean) {
    if (ocean[i][j]) return;
    int m = ocean.size();
    int n = ocean[0].size();

    ocean[i][j] = true;
    queue<pair<int, int>> q;
    q.emplace(i, j);
    while (!q.empty()) {
      auto [row, col] = q.front();
      q.pop();
      for (int k = 0; k < 4; k++) {
        int nr = row + di[k];
        int nc = col + dj[k];
        if (nr >= 0 && nr < m && nc >= 0 && nc < n && !ocean[nr][nc] &&
            heights[nr][nc] >= heights[row][col]) {
          ocean[nr][nc] = true;
          q.emplace(nr, nc);
        }
      }
    }
  }
};
// @lc code=end

int main() {
  vector<vector<int>> test1 = {{1, 2, 2, 3, 5},
                               {3, 2, 3, 4, 4},
                               {2, 4, 5, 3, 1},
                               {6, 7, 1, 4, 5},
                               {5, 1, 1, 2, 4}};
  Solution s;
  auto ans1 = s.pacificAtlantic(test1);
  return 0;
}
