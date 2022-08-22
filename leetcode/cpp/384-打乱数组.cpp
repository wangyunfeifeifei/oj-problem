/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  Solution(vector<int>& nums) {
    this->nums = nums;
    srand((unsigned long)time(NULL));
  }

  vector<int> reset() { return nums; }

  vector<int> shuffle() {
    int n = nums.size();
    vector<int> ret(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
      int j = rand() % (n - i) + i;
      swap(ret[i], ret[j]);
    }
    return ret;
  }

 private:
  vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end
