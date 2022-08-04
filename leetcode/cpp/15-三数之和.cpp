/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) return {};
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int k = 0; k < n - 2; k++) {
      if (k > 0 && nums[k - 1] == nums[k]) continue;
      int i = k + 1, j = n - 1;
      while (i < j) {
        int sum = nums[k] + nums[i] + nums[j];
        if (sum > 0) {
          j--;
        } else if (sum < 0) {
          i++;
        } else {
          ans.push_back({nums[k], nums[i], nums[j]});
          do {
            i++;
          } while (i < n && nums[i - 1] == nums[i]);
          do {
            j--;
          } while (j >= 0 && nums[j + 1] == nums[j]);
        }
      }
    }
    return ans;
  }
};
// @lc code=end
