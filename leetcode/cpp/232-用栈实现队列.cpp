/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

#include "include/headers.h"

// @lc code=start
class MyQueue {
 public:
  MyQueue() {}

  void push(int x) { input.push(x); }

  int pop() {
    int ret = peek();
    output.pop();
    return ret;
  }

  int peek() {
    if (empty()) throw "MyQueue is empty";
    if (!output.empty())
      return output.top();
    else {
      while (!input.empty()) {
        output.push(input.top());
        input.pop();
      }
      return output.top();
    }
  }

  bool empty() { return input.empty() && output.empty(); }

 private:
  stack<int> input;
  stack<int> output;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
