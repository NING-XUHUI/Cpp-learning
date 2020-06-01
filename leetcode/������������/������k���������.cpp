/*
已知一个使用字符串表示的非负整数num，将num中的k个数字移除，求移除k个数字后，可以获得的最小的可能的新数字。(num不会以0开头，num长度小于10002)
*/

#include <string>
#include <vector>
class Solution {
public:
  std::string removeKdigits(std::string num, int k) {
    std::vector<int> S;
    std::string result = "";
    for (int i = 0; i < num.length(); i++) {
      int number = num[i] - '0';
      while (S.size() != 0 && S[S.size() - 1] > number && k > 0) {
        S.pop_back();
        k--;
      }
      if (number != 0 || S.size() != 0) {
        S.push_back(number);
      }
    }
    while (S.size() != 0 && k > 0) {
      S.pop_back();
      k--;
    }
    for (int i = 0; i < S.size(); i++) {
      result.append(1, '0' + S[i]);
    }
    if (result == "") {
      result = "0";
    }
    return result;
  }
};
