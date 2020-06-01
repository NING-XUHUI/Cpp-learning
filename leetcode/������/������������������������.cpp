/*
已知k个已排序链表头结点指针，将这k个链表合并，合并后仍然为有序的，返回合并后的头节点
*/

#include <algorithm>
#include <vector>
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

bool cmp(const ListNode *a, const ListNode *b) { return a->val < b->val; }

class Solution {
public:
  ListNode *mergeKList(std::vector<ListNode *> &lists) {
    std::vector<ListNode *> node_vec;
    for (int i = 0; i < lists.size(); i++) {
      ListNode *head = lists[i];
      while (head) {
        node_vec.push_back(head);
        head = head->next;
      }
    }
    if (node_vec.size() == 0) {
      return NULL;
    }
    std::sort(node_vec.begin(), node_vec.end(), cmp);
    for (int i = 1; i < node_vec.size(); i++) {
      node_vec[i - 1]->next = node_vec[i];
    }
    node_vec[node_vec.size() - 1]->next = NULL;
    return node_vec[0];
  }

  ListNode *mergeKList1(std::vector<ListNode *> &lists) {
    if (lists.size() == 0) {
      return NULL;
    }
    if (lists.size() == 1) {
      return lists[0];
    }
    if (lists.size() == 2) {
      //调用上一题函数
    }
    int mid = lists.size() / 2;

    std::vector<ListNode *> sub1_lists;
    std::vector<ListNode *> sub2_lists;

    for (int i = 0; i < mid; i++) {
      sub1_lists.push_back(lists[i]);
    }
    for (int i = mid; i < lists.size(); i++) {
      sub2_lists.push_back(lists[i]);
    }
    ListNode *l1 = mergeKList1(sub1_lists);
    ListNode *l2 = mergeKList1(sub2_lists);

    return mergeTwoLists(l1, l2);
  }
};
