/*
已知从1至n的数字序列，按顺序入栈，每个数字入栈后即可出栈，也可在栈中停留，等待后面的数字入栈出栈后，该数字在出栈，求该数字序列的出栈序列是否合法？
思路：使用栈和队列模拟入栈出栈过程
*/

#include <queue>
#include <stack>
#include <stdio.h>

bool check_is_valid_order(std::queue<int> &order) {
  std::stack<int> S;
  int n = order.size();
  for (int i = 1; i <= n; i++) {
    S.push(i);
    while (!S.empty() && order.front() == S.top()) {
      S.pop();
      order.pop();
    }
  }
  if (!S.empty())
    return false;
  else
    return true;
}

int main(){
  std::queue<int> q;
  q.push(3);
  q.push(2);
  q.push(1);
  q.push(5);
  q.push(4);

  if(check_is_valid_order(q))
    printf("YES");
  else
    printf("NO");

  return 0;
}
