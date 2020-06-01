//反转列表
#include<iostream>
using namespace std;

struct Node
{
	Node* next;
	int value;
};

static Node* reverseList(Node* n){//将所有指针反向指
	Node* prev = 0;
	while(n){
		Node* next = n->next;
		n->next = prev;
		prev = n;
		n = next;
	}
	n = prev;//n指向最后一个节点
	return n;
}

int main(){

  return 0;
}
