#include<iostream>
#include<iterator>
#include<algorithm>
#include<vector>

using namespace std;

//将来自输入迭代器的n个T类型数值排序麻将结果通过输出迭代器result输出
template<class T,class InputIterator,class OutputIterator>
void mySort(InputIterator first,InputIterator last,OutputIterator result){
  //通过输入迭代器将输入数据存入向量容器s中
  vector<T>s;
  for(;first!=last;++first){
    s.push_back(*first);
  }
  //对s进行排序，sort函数的参数必须是随机访问迭代器
  sort(s.begin(),s.end());
  copy(s.begin(),s.end(),result);//将s序列通过输出迭代器输出
}

int main(){
  double a[5] = {1.2,2.4,0.9,3.3,3.2};
  mySort<double>(a,a+5,ostream_iterator<double>(cout," "));
  cout<<endl;
  //从标准输入读入若干个整数，将排序后的结果输出
  mySort<int>(istream_iterator<int>(cin),istream_iterator<int>(),ostream_iterator<int>(cout," "));
  cout<<endl;
  return 0;
}

/*迭代器辅助函数

advance(p,n)
  对p执行n次自增操作
distance(first,last)
  计算两个迭代器first和last的距离，即对first执行多少次++才能是的first==last
*/
 
