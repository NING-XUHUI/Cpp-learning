/*
  已知链表头节点指针head，将链表从位置m到n逆序
*/

struct ListNode {
  int val;
  ListNode *next;
};

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    int change_len = n - m + 1;
    ListNode *pre_head = nullptr;
    ListNode *result = head;
    while (head && --m) {
      pre_head = head;
      head = head->next;
    }
    ListNode *modify_list_tail = head;
    ListNode *new_head = nullptr;
    while (head && change_len) {
      ListNode *temp = head->next;
      head->next = new_head;
      new_head = head;
      head = temp;
      change_len--;
    }
    modify_list_tail->next = head;

    if (pre_head) {
      pre_head = new_head;
    } else {
      result = new_head;
    }
    return result;
  }
};
