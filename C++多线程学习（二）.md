# C++多线程学习（二）

## 值传递及引用传递

* 创建类A作为线程的入口

~~~cpp
class A {  zzc
  	int m_i;
  	//类型转换构造函数
  	A(int a) : m_i(a) {
    	cout << "A::A(int a)" << std::this_thread::get_id() << endl;
  }
  	A(const A &a) : m_i(a.m_i) {
    		cout << "A::A(const A& a)" << std::this_thread::get_id() << endl;
  }
  	~A() { cout << "A::~A()" << std::this_thread::get_id() << endl; }
};
~~~

~~~cpp
void my_print1(const int i,const string& pmyprint)
{
	cout << i << endl;				//实际上是值传递，即使主线程对子线程进行detach()，子线程依然安全。
	cout << pmyprint.c_str() << endl;	//但是如果是指针，那么肯定会出现问题。
}

int main(){
	int mvar = 1;
	int &myvar = mvar;
	char mybuf[] = "this is a test";
	thread my_t1(myprint1,mvar,mybuf);
	
	return 0;
}
~~~
* 只要以临时构造的A类作为参数传递给线程，那么一定能保证子线程的运行安全
* 若传递int这种简单数据类型，建议都是值传递
* 如果传递类对象，应该避免隐式类型转换，全部在创建线程这一行构建出临时对象，如果在函数参数里使用引用，否则系统还会多构造一个类对象。
* 结论：为保证线程的绝对安全，应尽可能不使用detach()，而是使用join()。
* std::this_thread::get_id()来获取目前线程的id。

将`thread my_t1(myprint1,mvar,mybuf);` 更改为`thread my_t1(myprint1,mvar,string(mybuf));`
即可以避免在子线程尚未结束，而主线程已经结束，将变量内存释放，导致子线程中出现访问未知内存的错误。

~~~cpp
void my_print2(const int i,const A &my_A)
{
	cout << &my_A.m_i << endl;
}

int main(){
	int mvar = 1;
	int mysecondvar = 12;
	thread my_t2(my_print2,mvar,A(mysecondvar));//希望mysecondvar转换为A类对象
												//在创建线程的同时构造临时对象的方法传参数是可行的
	cout << "Leoning" << endl;
}
~~~




