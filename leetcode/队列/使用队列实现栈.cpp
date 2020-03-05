/*
  设计一个栈，支持基本的栈操作，这个栈的内存存储数据的结构为队列，队列的方法只能包括push、front、pop、size、empty等标准队列方法
*/
#include <queue>
#include <stdio.h>
class Mystack {
public:
  Mystack() {}
  void push(int x) {
    std::queue<int> temp_queue;
    temp_queue.push(x);
    //将数据转移到临时队列
    while (!_data.empty()) {
      temp_queue.push(_data.front());
      _data.pop();
    }
    //再将数据转移回自己
    while (!temp_queue.empty()) {
      _data.push(temp_queue.front());
      temp_queue.pop();
    }
  }
  int pop() {
    int x = _data.front();
    _data.pop();
    return x;
  }
  int top() { return _data.front(); }
  bool empty() { return _data.empty(); }

private:
  std::queue<int> _data;
};

int main() {
  Mystack S;
  S.push(1);
  S.push(2);
  S.push(3);
  S.push(4);
  printf("%d\n", S.top());
  S.pop();
  printf("%d\n", S.top());
  S.push(5);
  printf("%d\n", S.top());

  return 0;
}
