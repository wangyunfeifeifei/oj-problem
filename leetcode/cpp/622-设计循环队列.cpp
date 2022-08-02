/*
 * @lc app=leetcode.cn id=622 lang=cpp
 *
 * [622] 设计循环队列
 */

#include "include/headers.h"

// @lc code=start
class MyCircularQueue {
 public:
  MyCircularQueue(int k) {
    size = k + 1;
    rear = prev = 0;
    queue = vector<int>(size);
  }

  bool enQueue(int value) {
    if (isFull()) return false;
    rear = (rear + 1) % size;
    queue[rear] = value;
    return true;
  }

  bool deQueue() {
    if (isEmpty()) return false;
    prev = (prev + 1) % size;
    return true;
  }

  int Front() {
    if (isEmpty()) return -1;
    return queue[(prev + 1) % size];
  }

  int Rear() {
    if (isEmpty()) return -1;
    return queue[rear];
  }

  bool isEmpty() { return rear == prev; }

  bool isFull() { return (rear + 1) % size == prev; }

 private:
  int rear, prev;
  int size;
  vector<int> queue;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end
