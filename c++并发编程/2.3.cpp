#include <iostream>
#include <thread>
using namespace std;
void some_function();
void some_other_function();

/**
 * 从函数中返回thread
 */ 

std::thread f(){
    void some_function();
    return std::thread(some_function);
}

std::thread g(){
    void some_other_function(int);
    std::thread t(some_other_function,42);
    return t;
}

void ff(std::thread t);
void gg(){
    void some_function();
    ff(std::thread(some_function));
    std::thread t(some_function);
    ff(std::move(t));
    
}

int main()
{
    std::thread t1(some_function);
    std::thread t2 = std::move(t1);
    t1 = std::thread(some_other_function);
    std::thread t3;
    t3 = std::move(t2);
    t1 = std::move(t3);    //这一步将终止程序，因为t1与some_other_func相关联，所以会调用std::terminate来终止程序

    return 0;
}

