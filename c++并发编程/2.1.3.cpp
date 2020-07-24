#include <iostream>
#include <thread>

using namespace std;

void do_something(int &i){
    i++;
}

struct func{
    int& i;
    func(int &i_):i(i_){}
    void operator()(){
        for(unsigned j = 0;j < 100000;j++){
            do_something(i);
        }
    }
};

void do_something_in_current_thread(){
    //... something in current thread
}

void f(){
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread t(my_func);
    //  为避免应用程序在引发异常时被种植，需要在非异常情况下调用join函数，也要在异常情况下调用join函数
    try{
        do_something_in_current_thread();
    }catch(){
        t.join();
        throw;
    }
    t.join();
}

int main()
{
    return 0;
}

