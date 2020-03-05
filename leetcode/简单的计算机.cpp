/*
  设计一个简单的计算机，输入一个字符串存储的数学表达式，可以计算包括（）、+、-四种符号的数学表达式，输入的数学表达式字符串保证是合法的，输入的数学表达式可能存在空格字符。
*/
#include <stack>
void compute(std::stack<int> &number_stack, std::stack<char> &operator_stack) {
  if (number_stack.size() < 2) {
    return;
  }
  int num2 = number_stack.top();
  number_stack.pop();
  int num1 = number_stack.top();
  number_stack.pop();
  if (operator_stack.top() == '+') {
    number_stack.push(num1 + num2);
  } else if (operator_stack.top() == '-') {
    number_stack.push(num1 - num2);
  }
  operator_stack.pop(); 
}
