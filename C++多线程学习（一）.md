# C++多线程学习（一）
## 线程与进程

头文件`#include<thread>`

~~~cpp
int main(){
	cout << "Leoning" << endl;
	return 0;
}
~~~

* main函数为主线程，此时主线程执行，当主线程return时，则进程结束。

* 自己创建的线程也需要从一个函数开始执行（初始函数）。

* 当这个函数执行完毕时，代表这个线程运行结束。

* 一般情况下如果其他子线程还没有执行完毕，那么这些子线程会被强行终止，所以，如果想保持子线程的运行状态，那么一定要让主线程一直保持运行，不让主线程执行完毕。

## 线程的基本操作
### join()
~~~cpp
void my_print(){
    cout << "我的线程开始了" <<endl;
    cout << "我的线程结束了" <<endl;
}
~~~ 
在main函数中创建以my_print为初始函数的线程

~~~cpp
int main(){
	thread my_t(my_print);
	my_t.join();
	cout << "Leoning" << endl;
	return 0;
}
~~~

* 线程在被创建时便开始执行，join()命令主线程等待子线程执行完毕，才能结束主线程。

### detach()

~~~cpp
int main(){
	thread my_t(my_print);
	my_t.detach();
	cout << "Leoning" << endl;
	return 0;
}
~~~

* detach()则与join()相反，主线程无需等待子线程的执行完毕，便可以自行结束整个进程。

### joinable()

~~~cpp
int main(){
	thread my_t(my_print);
	if (my_t.joinable)
		my_t.join();
	cout << "Leoning" << endl;
	return 0;
}
~~~

* joinable()返回true或false，判断某个线程是否可以使用join()或detach()。
* 某个线程一旦detach()过后，就不可以再使用join()。

## 创建线程的基本方法

### 普通函数创建

* 上述线程就是使用普通函数my_print创建

### 类创建
~~~cpp
class TA{
public:
    int &m_i;
    TA(int &i):m_i(i){ }
    void operator()(){
        cout << "我的线程开始执行" <<endl;
        cout << "m_i:" << m_i << endl;
        cout << "m_i:" << m_i << endl;
        cout << "m_i:" << m_i << endl;
        cout << "结束" <<endl;
    }
};

int main(){
	int myi = 6;
	TA ta(myi);
	thread my_t2(ta);
	my_t2.join();
	cout << "Leoning" << endl;
	return 0;
}
~~~

### lambda函数
~~~cpp
int main(){
	auto mylambda = []{
		cout << "开始" << endl;
		cout << "结束" << endl;
	};
	thread my_t3(mylambda);
	my_t3.join();
	cout << "Leoning" << endl;
	return 0;
}
~~~
