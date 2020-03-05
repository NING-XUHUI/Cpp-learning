/*
已知一个未排序的数组，求这个数组中第K大的数字
*/

#include <queue>
#include <vector>

class Solution {
public:
  int findKthLargest(std::vector<int> &nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> Q;
    for (int i = 0; i < nums.size(); i++) {
      if (Q.size() < k) {
        Q.push(nums[i]);
      } else if (Q.top() < nums[i]) {
        Q.pop();
        Q.push(nums[i]);
      }
    }
    return Q.top();
  }
};

int main() {
  std::vector<int> nums;
  nums.push_back(3);
  nums.push_back(2);
  nums.push_back(1);
  nums.push_back(5);
  nums.push_back(6);
  nums.push_back(4);
  Solution solve;
  printf("%d", solve.findKthLargest(nums, 2));

  return 0;
}
