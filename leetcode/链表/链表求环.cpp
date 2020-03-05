/*
已知链表中可能存在环，若又换返回环起始节点，否则返回null
*/
//快慢指针

#include <set> //同交点
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
  ListNode* detectCycle(ListNode *head){
    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *meet = nullptr;
    while(fast){
      slow = slow->next;
      fast = fast->next;
      if(!fast){
        return nullptr;
      }
      fast = fast->next;
      if(fast == slow){
        meet = fast;
        break;
      }
    }
    if(meet == nullptr){
      return nullptr;
    }
    while(1){
      if(head == meet){
        return head;
      }
      head = head->next;
      meet = meet->next;
    }
    return nullptr;
  }
};
