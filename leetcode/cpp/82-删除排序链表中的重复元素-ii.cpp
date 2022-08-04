/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 */

#include "include/headers.h"

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) return nullptr;
    ListNode *ret = nullptr, *pre = nullptr, *p = head;
    while (p != nullptr) {
      int cnt = 1;
      ListNode* q = nullptr;
      for (q = p->next; q != nullptr && q->val == p->val; q = q->next) {
        cnt++;
      }
      if (cnt == 1) {
        // 无重复
        if (pre == nullptr) {
          pre = p;
          ret = p;
        } else {
          pre->next = p;
          pre = p;
        }
      } else if (pre != nullptr) {
        pre->next = nullptr;  // 先将指针置空
      }
      p = q;
    }
    return ret;
  }
};
// @lc code=end
