/*

STL算法

  STL算法本身是一种函数模版
    通过迭代器获得输入数据
    通过函数对象对数据进行处理
    通过迭代器将结果输出

STL算法是通用的，独立于具体的数据类型、容器类型

*/
/*
分类

1.不可变序列算法
  不直接修改所操作容器内容的算法
  用于查找指定元素、比较连哥哥序列是否相等、对元素进行计数等
  例如：
  template<class InputIterator,class UnaryPredicate>
  InputIterator find_if(InputIterator first,InputIterator last,UnaryPredicate);
  查找[first,last)区间内pred(x)为真的首个元素
2.可变序列算法
  可以修改它们所操作的容器对象
  包括对序列进行复制、删除、替换、倒叙、旋转、交换、分割、去重、填充、洗牌的算法即生成一个序列的算法
  例如：
  template<class ForwardIterator,class T>
  InputIterator find_if(ForwardIterator first,ForwardIterator last,const T& x);
  将[first,last)区间内的元素全部改修为x。
3.排序和搜索算法
  对序列进行排序
  对两有序序列进行合并
  对有序序列进行搜索
  有序序列的集合操作
  堆算法
  例如：
  template<class RandomAccessIterator,class UnaryPredicate>
  void sort(RandomAccessIterator first,RandomAccessIterator last,UnaryPredicate comp);
  以函数对象comp为"<",对[first,last)区间内的数据进行排序
4.数值算法
  求序列中元素的“和”、部分“和”、相邻元素的“差”或两序列的内积
  求“和”的“+”、求“差”的“-”以及求内积的“+”和“·”都可以有函数对象指定
  例如：
  template<class InputIterator,class OutputIterator,class BinaryFunction>
  OutputIterator partial_sum(InputIterator first,InputIterator last,OutputIterator result,BinaryFunction op);
  对[first,last)内的元素求部分“和”（所谓部分“和”，是一个长度与输入序列相同的序列，其第n项为输入序列前n个元素的“和”），以函数对象op为“+”运算符，结果通过result输出，返回的丢带起指向输出序列最后一个元素的下一个元素
*/
