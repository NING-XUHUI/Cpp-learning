//先按从大到小的顺序输出奇数，再按照从小到大的顺序输出偶数


#include<iterator>
#include<vector>
#include<deque>
#include<iostream>

using namespace std;
int main(){

  istream_iterator<int>i1(cin),i2;//建立一堆输入流迭代器
  vector<int>s1(i1,i2);//通过输入流迭代器从标准输入流中输入数据
  sort(s1.begin(),s1.end());//将输入的整数排列
  deque<int>s2;
  //以下循环遍历s1
  for(vector<int>::iterator iter = s1.begin();iter != s1.end();++iter){
    if(*iter%2==0)//偶数放在s2的尾部
      s2.push_back(*iter);
    else
      s2.push_front(*iter);
  }
  //将s2的结果输出
  copy(s2.begin(),s2.end(),ostream_iterator<int>(cout," "));
  cout<<endl;
  return 0;
}
/*
列表
特点
  在任意位置插入和删除元素都很快
  不支持随机访问
接合(splice)操作
s1.splice(p,s2,q1,q2):将s2中[q1,q2)移动到s1中p所指向元素之前
*/
