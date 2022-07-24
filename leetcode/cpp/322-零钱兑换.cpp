/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    sort(coins.begin(), coins.end(), [](int a, int b) { return a > b; });
    mem = vector<int>(amount + 1, -2);
    mem[0] = 0;
    return count(coins, amount);
  }

 private:
  int count(vector<int>& coins, int amount) {
    if (amount < 0)
      return -1;
    else if (amount == 0)
      return 0;
    if (mem[amount] != -2) return mem[amount];
    int ret = INT_MAX;
    for (int i = 0; i < coins.size(); i++) {
      if (amount >= coins[i]) {
        int t = count(coins, amount - coins[i]);
        if (t != -1 && t + 1 < ret) {
          ret = t + 1;
        }
      }
    }
    ret = ret == INT_MAX ? -1 : ret;
    mem[amount] = ret;

    return ret;
  }

 private:
  vector<int> mem;
};
// @lc code=end

int main() {
  vector<int> coins1 = {1, 2, 5};
  Solution s;
  int ans = s.coinChange(coins1, 11);
  cout << ans;
  return 0;
}
