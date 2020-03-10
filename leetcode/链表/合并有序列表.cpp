/*
已知两个排序链表头节点指针l1和l2，将这两个链表合并，合并后仍然为有序的，返回合并后的头节点
*/

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode temp_head(0);
    ListNode *pre = &temp_head;
    while (l1 && l2) {
      if (l1->val < l2->val) {
        pre->next = l1;
        l1 = l1->next;
      } else {
        pre->next = l2;
        l2 = l2->next;
      }
      pre = pre->next;
    }
    if (l1) {
      pre->next = l1;
    }
    if (l2) {
      pre->next = l2;
    }
    return temp_head.next;
  }
};
