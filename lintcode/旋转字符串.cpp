/*
8.旋转字符串
给定一个字符串（以字符数组的形式给出）和一个偏移量，根据偏移量原地旋转字符串(从左向右旋转)。
*/

class Solution{
public:
  /**
         * @param str: An array of char
         * @param offset: An integer
         * @return: nothing
         */
  void rotateString(string &str,int offset){
    int space = str.size();
    if(offset == 0 || space == 1 || space == 0)return;
    offset %= space;
    for(int i = 1;i <= offset;i++){
      char a = str[0];
      for(int j = space - 1;j > 0;j--){
	str[(j + 1)%space] = str[j];
      }
      str[1] = a; 
    }
  }
};
