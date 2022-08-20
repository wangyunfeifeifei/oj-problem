/*
 * @lc app=leetcode.cn id=1450 lang=cpp
 *
 * [1450] 在既定时间做作业的学生人数
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
    int ans = 0;
    int n = startTime.size();
    for (int i = 0; i < n; i++) {
      if (queryTime >= startTime[i] && queryTime <= endTime[i]) {
        ans++;
      }
    }
    return ans;
  }
};
// @lc code=end
