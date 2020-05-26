#include <iostream>
#include <memory>
#include <string>
using namespace std;

/*
unique指针只能有一个对象拥有所有权
*/

struct Person {
  ~Person() { cout << "~Person()" << endl; }

  string str;
};

unique_ptr<Person> test() { return unique_ptr<Person>(new Person); }

template <typename T> struct Node {
  T data;
  unique_ptr<Node<T> > next;
  ~Node(){
    cout << "~Node()" << endl;
  }
};

template <typename T> class Link {
	public:
  void front(const T &data) {
    auto node = make_unique<Node<T> >();
    node->data = data;
    node->next = move(head_.next);
    head_.next = move(node);
  }

  void print() {
    Node<T> *node = head_.next.get();
    while (node) {
      cout << node->data << ' ';
      node = node->next.get();
    }
      cout << endl;
  }

private:
  Node<T> head_;
};

int main(int argc, char const *argv[]) {
  // unique_ptr<Person> p1 = test();
  // p1->str = "hello";
  // unique_ptr<Person> p2 = move(p1);

  // p2.reset(new Person);
  // if (!p1)
  // {
  // 	cout << "p1 is empty" << endl;
  // }

  // if (p2)
  // {
  // 	cout << "p2 is not empty" << endl;
  // }

  // cout << p2->str << endl;

  //   auto ptr = make_shared<Person>();

  //   ptr->str = "hello";
  Link<int> lk;

  for(int val : {1,2,3,4,5 }){
	  lk.front (val);
  }
  lk.print();
  return 0;
}
