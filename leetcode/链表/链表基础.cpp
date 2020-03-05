#include<stdio.h>

struct ListNode{
  int val;
  ListNode *next;
};

int main(){
  ListNode a;
  ListNode b;
  ListNode c;
  ListNode d;
  ListNode e;
  a.val = 1;
  b.val = 2;
  c.val = 3;
  d.val = 4;
  e.val = 5;
  a.next = &b;
  b.next = &c;
  c.next = &d;
  d.next = &e;
  e.next = nullptr;
  ListNode* head = &a;
  while(head){
    printf("%d\n",head->val);
    head = head->next;
  }

  return 0;
}
