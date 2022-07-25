/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

#include "include/headers.h"

// @lc code=start
class MinStack {
 public:
  MinStack() {}

  void push(int val) {
    st.push(val);
    if (mst.empty() || val <= mst.top()) {
      mst.push(val);
    }
  }

  void pop() {
    if (top() == getMin()) {
      st.pop();
      mst.pop();
    } else {
      st.pop();
    }
  }

  int top() { return st.top(); }

  int getMin() { return mst.top(); }

 private:
  stack<int> st;
  stack<int> mst;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
