/*
已知链表头节点指针head，将链表逆序，不可以申请额外空间
*/

struct ListNode {
  int val;
  ListNode *next;
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *new_head = nullptr;
    while (head) {
      ListNode *next = head->next;
      head->next = new_head;
      new_head = head;
      head = next;
    }
    return new_head;
  }
};
