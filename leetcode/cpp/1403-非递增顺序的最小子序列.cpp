/*
 * @lc app=leetcode.cn id=1403 lang=cpp
 *
 * [1403] 非递增顺序的最小子序列
 */

#include "include/display.h"
#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  vector<int> minSubsequence(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });
    int lsum = 0;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
      lsum += nums[i];
      if (lsum <= sum - lsum) {
        ans.push_back(nums[i]);
      } else {
        ans.push_back(nums[i]);
        break;
      }
    }
    return ans;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> test1{4, 3, 10, 9, 8};
  auto ret = s.minSubsequence(test1);
  displayVec(ret);
  return 0;
}
