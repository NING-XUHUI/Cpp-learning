/*
给一个整数数组，找到两个数使得他们的和等于一个给定的数 target。

你需要实现的函数twoSum需要返回这两个数的下标, 并且第一个下标小于第二个下标。注意这里下标的范围是 0 到 n-1。
*/

#include <vector>
using namespace std;
class Solution{
public:
  /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1, index2] (index1 < index2)
     */
  vector<int>twoSum(vector<int>&numbers,int target){
    int i = 0;
    int j = 0;
    vector<int>re;
    for(i = 0;i < numbers.size();i++){
      for(j = i + 1; j <numbers.size();j++){
	if((numbe#include <vector>
        using namespace std;rs[i] + numbers[j] == target)){
	  re.push_back(i);
	  re.push_back(j);
	  return re;
	}
	else{
	  continue;
	}
      }
    }
  }
  
};
