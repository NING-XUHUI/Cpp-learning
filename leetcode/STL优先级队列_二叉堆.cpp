//二叉堆，最小或最大值先出的完全二叉树

#include <queue>
#include <stdio.h>

int main() {
  std::priority_queue<int> big_heap; //默认构造最大堆
  std::priority_queue<int, std::vector<int>, std::greater<int>>
      small_heap; //最小堆构造
  std::priority_queue<int, std::vector<int>, std::less<int>> big_heap2; //最大堆
  if (big_heap.empty()) {
    printf("big_heap is empty!\n");
  }
  int test[] = {6, 10, 1, 7, 99, 4, 33};
  for (int i = 0; i < 7; i++) {
    big_heap.push(test[i]);
  }
  printf("big heap.top = %d\n", big_heap.top());
  big_heap.push(1000);
  printf("big heap.top = %d\n", big_heap.top());
  for (int i = 0; i < 3; i++) {
    big_heap.pop();
  }
  printf("big heap.top = %d\n", big_heap.top());
  printf("big heap.size = %lu\n", big_heap.size());

  return 0;
}
