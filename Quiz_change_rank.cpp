#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <vector>

/*===============================
假设有一个容器里面存的数据好似无序的
例如是 1 5 3 5 6 7 100
函数传入这个容器和一个索引值例如3
函数将这个容器的内容根据传输的为止进行调整，经过调整后
变成6 7 100 5 1 5 3
就是在位置3之后的放在前面，位置3之前的放在后面
changeOrder({1,2,3},0)-> 2 3 1
changeOrder({1,2,3},1)-> 3 2 1
changeOrder({1,2,3},2)-> 3 1 2
假设我们不考虑pos无效的情况 pos >= 0 && pos < objects.size()
========================
*/

void changeOrder(std::vector<int> &objects, int pos) {
  assert(pos >= 0);
  assert(pos < objects.size());
  std::rotate(objects.begin(), objects.end() + pos, objects.end());
  //等价
  std::rotate(objects.begin(), objects.begin() + 1,
              objects.begin() + (objects.size() - pos));
}

int main(int argc, char *argv[]) { return 0; }
