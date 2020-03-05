/*
设计一个栈，支持如下操作，这些操作的算法复杂度需要是常量级，O(1)
1.push(x)
2.pop()
3.top()
4.getMin()
*/
#include <stack>
#include <stdio.h>
class Mystack {
private:
  std::stack<int> min;
  std::stack<int> S;

public:
  Mystack() {}
  void push(int x) {
    if (S.empty()) {
      min.push(x);
    } else {
      if (min.top() > x)
        min.push(x);
    }
    S.push(x);
  }
  int pop() {
    if (S.top() == min.top()) {
      min.pop();
    }
    int x = S.top();
    S.pop();
    return x;
  }

  int top() { return S.top(); }
  int getMin() { return min.top(); }
};

int main() {
  Mystack S;
  S.push(0);
  S.push(-2);
  S.push(-1);
  printf("%d\n", S.top());
  printf("%d\n", S.getMin());
  S.push(-5);
  S.push(-4);
  printf("%d\n", S.getMin());
  S.pop();
  printf("%d\n", S.getMin());
  S.pop();
  printf("%d\n", S.getMin());
  
  return 0;
}
