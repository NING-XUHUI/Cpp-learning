/*
已知链表A的头结点为headA，链表B的有结点指针headB，两个链表相交，求两链表交点对应的节点。
1.若无交点，返回null
2.不能破坏两个链表
3.保证无环
4.时间O(n),空间O(1)
*/

#include <set>
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

//遍历A，将A中节点对应指针插入set
//遍历B，将B中节点对应指针在set查找，发现第一个，即为交点
class Solution1 {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    std::set<ListNode *> node_set;
    while (headA) {
      node_set.insert(headA);
      headA = headA->next;
    }
    while (headB) {
      if (node_set.find(headB) != node_set.end()) {
        return headB;
      }
      headB = headB->next;
    }
    return nullptr;
  }
};

class Solution2 {
public:
  int get_list_length(ListNode *head) {
    int len = 0;
    while (head) {
      len++;
      head = head->next;
    }
    return len;
  }
  ListNode *forward_long_list(int long_len, int short_len, ListNode *head) {
    int delta = long_len - short_len;
    while (head && delta) {
      head = head->next;
      delta--;
    }
    return head;
  }

  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int list_A = get_list_length(headA);
    int list_B = get_list_length(headB);
    if (list_A > list_B) {
      headA = forward_long_list(list_A, list_B, headA);
    } else {
      headB = forward_long_list(list_B, list_A, headB);
    }
    while (headA && headB) {
      if (headA == headB) {
        return headA;
      }
      headA = headA->next;
      headB = headB->next;
    }
    return nullptr;
  }
};
