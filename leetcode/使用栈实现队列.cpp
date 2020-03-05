/*
  设计一个队列，支持基本的队列操作，这个队列的内部存储数据的结构为栈，栈的方法只能包括push、pop、top、size、empty等标准栈方法
*/

#include <stack>
#include <stdio.h>

class Myqueue {
public:
  Myqueue() {}
  void push(int x) {
    std::stack<int> temp_stack;
    while (!_data.empty()) {
      temp_stack.push(_data.top());
      _data.pop();
    }
    _data.push(x);
    while (!temp_stack.empty()) {
      _data.push(temp_stack.top());
      temp_stack.pop();
    }
  }
  int pop() {
    int x = _data.top();
    _data.pop();
    return x;
  }

  int peek() { return _data.top(); }

  bool empty() { return _data.empty(); }

private:
  std::stack<int> _data;
};

int main(){
  Myqueue Q;
  Q.push(1);
  Q.push(2);
  Q.push(3);
  Q.push(4);
  printf("%d\n",Q.peek());
  Q.pop();
  printf("%d\n",Q.peek());
  return 0;
}
