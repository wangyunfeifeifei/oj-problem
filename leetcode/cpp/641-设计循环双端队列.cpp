/*
 * @lc app=leetcode.cn id=641 lang=cpp
 *
 * [641] 设计循环双端队列
 */

#include "include/headers.h"

// @lc code=start
class MyCircularDeque {
 public:
  MyCircularDeque(int k) {
    rear = front = 0;
    sz = k + 1;
    dq = vector<int>(sz);
  }

  bool insertFront(int value) {
    if (isFull()) return false;
    dq[front] = value;
    front = (front + sz - 1) % sz;
    return true;
  }

  bool insertLast(int value) {
    if (isFull()) return false;
    rear = (rear + 1) % sz;
    dq[rear] = value;
    return true;
  }

  bool deleteFront() {
    if (isEmpty()) return false;
    front = (front + 1) % sz;
    return true;
  }

  bool deleteLast() {
    if (isEmpty()) return false;
    rear = (rear + sz - 1) % sz;
    return true;
  }

  int getFront() {
    if (isEmpty()) return -1;
    return dq[(front + 1) % sz];
  }

  int getRear() {
    if (isEmpty()) return -1;
    return dq[rear];
  }

  bool isEmpty() { return rear == front; }

  bool isFull() { return (rear + 1) % sz == front; }

 private:
  int front, rear;
  int sz;
  vector<int> dq;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end
