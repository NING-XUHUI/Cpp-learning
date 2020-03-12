/*
已知一个复杂的链表，节点中有一个指向本链表任意某个节点的随机指针，可以为空，求这个链表的深层拷贝
*/

#include <map>
#include <vector>
struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    std::map<RandomListNode *, int> node_map;
    std::vector<RandomListNode *> node_vector;
    RandomListNode *ptr = head;
    int i = 0;
    while (ptr) {
      node_vector.push_back(new RandomListNode(ptr->label));
      node_map[ptr] = i;
      ptr = ptr->next;
      i++;
    }

    node_vector.push_back(0);
    ptr = head;
    i = 0;
    while (ptr) {
      node_vector[i]->next = node_vector[i + 1];
      if (ptr->random) {
        int id = node_map[ptr->random];
        node_vector[i]->random = node_vector[id];
      }
      ptr = ptr->next;
      i++;
    }
    return node_vector[0];
  }
};
