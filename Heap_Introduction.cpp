/*
一、Heap & Tree
优先级队列

若队列为unsorted:
	插入数据复杂度：O(1)*	移除最小值复杂度：O(n)	数组
	插入数据复杂度：O(1)	移除最小值复杂度：O(n)	链表

若队列为sorted:
	插入数据复杂度：O(n)	移除最小值复杂度：O(1)	数组
	插入数据复杂度：O(n)	移除最小值复杂度：O(1)	链表

(min)Heap:
A complete binary tree T is a min-heap if:
·T = {} or
·T = (r,Tl.Tr},where r is less than the roots of {Tl,Tr}and{Tl,Tr}are
min-heaps.
#the parent is going to be smaller than all of its descendants
所有父节点都比它自己的子节点小，无跨越!

#parent is eaqual to our index divided by two
Lchild = i * 2
Rchild = i * 2 + 1
父节点的下标等于子节点的下标除以二(all int)

二、Heap_Insert
在插入数据时，先将数据放在数组的最后一位，接着与父节点进行比较，若不符合大小关系，
则直接交换父子节点。
  代码见l40-l59
三、移除最小值
  代码见l61-l82
四、建立Heap
  代码见l83-l95
五、运行时长分析
  Build heap O(n)
  n * removemin O(lg(n))= nlg(n)
  Swap elements

Runnung Time : n*lg(n)

*/

template<class T>
void Heap<T>::_insert(const T & key){
  //检查数组是否还有空间插入节点
  //若没有，则扩大数组容量
  if( size_ == capacity_){_growArray();}
  //插入新数据
  item_[++size] = key;

  //刷新栈的大小
  _heapifyUp(size);
}

 template <class T>
 void Heap<T>::_heapifyUp(int index){
   if(index > 1){
     if(item_[index] < item_[parent(index)]{
	std::swap(item_[index],item_[parent(index)]);
			     }
		}
 }

   template <class T>
     void Heap<T>::removeMin(){

     T minValue = item_[1];
     item_[1] = item_[size];
     size--;

     heapifyDown();

     return minValue;
   }

   template <class T>
     void Heap<T>::_heapifyDown(int index){
     if( !_isLeaf(index)){
       T minChildIndex = _minChild(index);
       if( item_[index] > item_[minChildIndex]){
	 std::swap(item_[index],item_[minChildIndex]);
	 _heapifyDown(minChildIndex);
       }
       }
   }

   template <class T>
   void Heap<T>::buildHeap(){
     for (unsigned i = 2;i <= size_;i++){
       heapifyUp(i);
     }
   }

   template <class T>
     void Heap<T>::buildHeap(){
     for (unsigned i = parent(size);i > 0;i--){
       heapifyDown(i);
     }
   }
