#include <iostream>
#include <memory>
#include <string>

using namespace std;

// 你需要申请，然后还需要释放一个资源，与一个对象的生命周期相绑定。


template<typename T>
class UniquePointer{
public:
	using Pointer = T*;
	using Reference = T&;

	UniquePointer():ptr_(nullptr){ }
	UniquePointer(Pointer ptr):ptr_(ptr){ }

	//move()
	UniquePointer(UniquePointer&& other)
		:ptr_(other.ptr_){
			other.ptr_ = nullptr;
		}

	UniquePointer& operator=(UniquePointer&& other){
		ptr_ = other.ptr_;
		other.ptr_ = nullptr;
		return *this;
	}

	UniquePointer(const UniquePointer&) = delete;
	UniquePointer& operator =(const UniquePointer&) = delete;

	~UniquePointer(){
		if (ptr_!=nullptr)
		{
			delete ptr_;
		}
	}

	operator bool(){
		return ptr_ != nullptr;
	}


	Pointer get() {
		return ptr_;
	}

	Reference operator*(){
		return *ptr_;
	}

	Pointer operator->() {
		return ptr_;
	}

	void reset(Pointer ptr = nullptr){
		if(ptr_!= nullptr){
			delete ptr_;
		}
		ptr_ = ptr;
	}

private:
	Pointer ptr_;
};


struct Demo
{
	~Demo(){
		cout << "析构函数" << endl;
	}
};

int main(int argc, char const *argv[])
{
	
	// UniquePointer<Demo> ptr(new Demo);

	// if(!ptr){
	// 	cout << "empty" << endl;
	// }

	UniquePointer<string> ptr(new string("hello"));

	ptr.reset(new string("hellssso"));
	if(ptr){
		cout << ptr->c_str() << endl;
	}

	return 0;
}