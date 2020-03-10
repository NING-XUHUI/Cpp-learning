/*
一个整数序列，如果两个相邻元素的差恰正负或负正交替出现，则该序列被称为摇摆序列，一个小于2个元素的序列直接为摇摆序列

给一个随机序列，求这个序列满足摇摆序列定义的最长子序列的长度
*/

#include <vector>

class Solution {
public:
  int wiggleMaxLength(std::vector<int> &nums) {
    if (nums.size() < 2) {
      return nums.size();
    }

    static const int BEGIN = 0;
    static const int UP = 1;
    static const int DOWN = 2;

    int STATE = BEGIN;
    int max_length = 1;

    for (int i = 1; i < nums.size();i++) {
      switch (STATE) {
      case BEGIN:
        if (nums[i] > nums[i - 1]) {
          STATE = UP;
          max_length++;
        } else if (nums[i - 1] > nums[i]) {
          STATE = DOWN;
          max_length++;
        }
        break;
      case UP:
        if (nums[i] < nums[i - 1]) {
          STATE = DOWN;
          max_length++;
        }
        break;
      case DOWN:
        if (nums[i] > nums[i - 1]) {
          STATE = UP;
          max_length++;
        }
        break;
      }
    }
    return max_length;
  }
};
