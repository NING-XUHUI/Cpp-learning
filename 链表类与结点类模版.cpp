/*
顺序访问的线性群体——链表类
  链表是一种动态数据结构，可以用来表示顺序访问的线性群体
  链表还有系列结点组成的，结点可以在运行时动态生成
  每一个结点包括数据域和指向链表中下一个结点的指针
  即下一个结点的地址，如果链表每个结点中只有一个指向后继结点的指针，则该
  链表称为单链表
 */

#include<iostream>
using namespace std;

//单链表结点类模版
template<class T>
class Node{
private:
  Node<T> *next;
public:
  T data;
  Node(const T& item,Node<T>* next = 0);
  void insertAfter(Node<T> *p);
  Node<T>* deleteAfter();
  Node<T>* nextNode()const;
};

template<class T>
void Node<T>::insertAfter(Node<T> *p){
  //p节点指针域指向当前结点的后继结点
  p->next = next;
  next = p;//当前结点的指针域指向p
}

template<class T>
Node<T>* Node<T>::deleteAfter(void){
  Node<T>* tempPtr = next;
  if(next == 0)
    return 0;
  next = tempPtr->next;
  return tempPtr;
}

int main(){

  return 0;
} 
