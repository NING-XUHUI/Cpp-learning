/*
已知一些孩子和一些糖果，每个孩子都有需求因子g，每个糖果有大小s，当某个糖果的大小s>=某个孩子的需求因子g时，代表该糖果可以满足该孩子，求使用这些糖果，最多能满足多少孩子？(每个孩子只能用1个糖果满足)
*/

#include <algorithm>
#include <vector>

class Solution {
public:
  int findContentChildren(std::vector<int> &g, std::vector<int> &s) {
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());
    int child = 0;
    int cookie = 0;
    while (g.size() != 0 && s.size() != 0) {
      if (g[child] <= s[cookie]) {
        child++;
        cookie++;
      }
      cookie++;
    }
    return child;
  }
};
