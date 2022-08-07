/*
 * @lc app=leetcode.cn id=636 lang=cpp
 *
 * [636] 函数的独占时间
 */

#include "include/display.h"
#include "include/headers.h"

// @lc code=start
class Solution {
 public:
  vector<int> exclusiveTime(int n, vector<string>& logs) {
    vector<int> ans(n, 0);
    stack<pair<int, int>> st;
    for (string& log : logs) {
      int chan;
      int time;
      char type[10];
      sscanf(log.c_str(), "%d:%[^:]:%d", &chan, type, &time);
      if (type[0] == 's') {
        if (!st.empty()) {
          ans[st.top().first] += time - st.top().second;
        }
        st.push({chan, time});
      } else {
        auto p = st.top();
        st.pop();
        ans[p.first] += time - p.second + 1;
        if (!st.empty()) {
          st.top().second = time + 1;
        }
      }
    }
    return ans;
  }
};
// @lc code=end

int main() {
  vector<string> logs{"0:start:0", "1:start:2", "1:end:5", "0:end:6"};
  Solution s;
  displayVec(s.exclusiveTime(2, logs));
  return 0;
}
