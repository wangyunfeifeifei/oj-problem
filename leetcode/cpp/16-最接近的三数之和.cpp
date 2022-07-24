/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int diff = INT_MAX;
    int ansIdx[3] = {-1, -1, -1};
    for (int k = 0; k < n; k++) {
      int i = 0, j = n - 1;
      while (i < j) {
        if (i == k) {
          i++;
          continue;
        }
        if (j == k) {
          j--;
          continue;
        }
        int sum = nums[i] + nums[j] + nums[k];
        int d = abs(sum - target);
        if (d < diff) {
          diff = d;
          ansIdx[0] = i;
          ansIdx[1] = j;
          ansIdx[2] = k;
        }
        if (sum == target)
          return sum;
        else if (sum < target) {
          i++;
        } else {
          j--;
        }
      }
    }
    auto [i, j, k] = ansIdx;
    return nums[i] + nums[j] + nums[k];
  }
};
// @lc code=end
