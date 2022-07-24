/*
 * @lc app=leetcode.cn id=815 lang=cpp
 *
 * [815] 公交路线
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  int numBusesToDestination(vector<vector<int>>& routes, int source,
                            int target) {
    if (source == target) {
      // 终点与起点相同
      return 0;
    }

    int n = routes.size();  // 共n条公交路线
    // 公交路线之间是否联通
    vector<vector<bool>> edge(n, vector<bool>(n, false));
    unordered_map<int, vector<int>> rec;  // 哪些路线能到达该站点
    for (int i = 0; i < n; i++) {
      for (int site : routes[i]) {         // 第i条路线有哪些站点
        for (int j : rec[site]) {          // 该站点哪些路线能到达
          edge[i][j] = edge[j][i] = true;  // 这两条路线能连通
        }
        rec[site].push_back(i);  // i路线能到达该站点
      }
    }

    vector<int> dis(n, -1);  // 距离
    queue<int> qu;
    for (int bus : rec[source]) {
      dis[bus] = 1;  // 第一辆公交
      qu.push(bus);  // 入队
    }

    while (!qu.empty()) {
      int x = qu.front();
      qu.pop();
      for (int y = 0; y < n; y++) {
        if (edge[x][y] && dis[y] == -1) {
          // 如果x路线能通往y路线, 并且之前没有更近的方案
          // 则，到y站需要乘坐的公交为到x路线站点乘坐公交+1;
          dis[y] = dis[x] + 1;
          qu.push(y);
        }
      }
    }
    int ret = INT_MAX;

    for (int bus : rec[target]) {
      if (dis[bus] != -1) {  // 能到达
        ret = min(ret, dis[bus]);
      }
    }

    return ret == INT_MAX ? -1 : ret;
  }
};
// @lc code=end
