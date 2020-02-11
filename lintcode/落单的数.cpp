/*
给出2*n + 1 个的数字，除其中一个数字之外其他每个数字均出现两次，找到这个数字。

样例
给出 [1,2,2,1,3,4,3]，返回 4
*/


class Solution{
public:
  /*
   *@param A:An integer array
   *@return:An inteher 
   */
  int singleNumber(vector<int>A){
    //这道题利用了异或位运算的一个性质，即：一个数与自身异或的结果为0。我们只需遍历数组中的每一个元素，并将其进行异或。因为，异或满足交换律，所以最终的异或结果将仅仅包含只出现一次的那个数。
    //如：1 ^ 2 ^ 2 ^ 1 ^3 ^ 4 ^ 3 = 1 ^ 1 ^ 2 ^ 2 ^ 3 ^ 3 ^ 4 = 4


    //采用异或的方法
    if(A.empty())return 0;
    int n = A[0];
    for(int i = 1;i != A.size();i++)
      n = n^A[i];
    return n;
  }

  
};
