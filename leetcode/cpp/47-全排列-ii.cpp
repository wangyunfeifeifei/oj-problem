/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    ans.push_back(nums);
    while (nextpermutation(nums)) {
      ans.push_back(nums);
    }
    return ans;
  }

 private:
  bool nextpermutation(vector<int>& nums) {
    // 找比当前序列大的最小的
    // 如果没有，则变为升序，返回false
    int n = nums.size();
    if (n <= 1) return false;
    bool flag = true;  // 默认是有比当前序列大的
    int i = n - 2, j = n - 1, k = n - 1;
    while (i >= 0 && nums[i] >= nums[j]) {
      // 找到第一对升序
      i--;
      j--;
    }
    if (i >= 0) {
      while (nums[k] <= nums[i]) k--;  // 找到比nums[i]大的最小的
      swap(nums[k], nums[i]);
    } else {
      flag = false;
    }
    reverse(nums.begin() + j, nums.end());  // 把[j, end)排序为升序
    return flag;
  }
};
// @lc code=end
