/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> edges(numCourses);  // 边
    vector<int> in(numCourses, 0);          // 入度
    vector<int> ret;                        // 结果

    for (int i = 0; i < prerequisites.size(); i++) {
      edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
      in[prerequisites[i][0]]++;
    }

    // 广度优先搜索
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
      // 入度为0的进队列
      if (in[i] == 0) {
        q.push(i);
      }
    }

    while (!q.empty()) {
      int c = q.front();
      q.pop();
      ret.push_back(c);
      for (int i = 0; i < edges[c].size(); i++) {
        --in[edges[c][i]];
        if (in[edges[c][i]] == 0) {
          q.push(edges[c][i]);
        }
      }
    }

    if (ret.size() != numCourses) return {};
    return ret;
  }
};
// @lc code=end
