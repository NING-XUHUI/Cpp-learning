#include <iostream>
#include <thread>

void hello(){
    std::cout<<"Hello Concurrent World !"<<std::endl;
}

class thread_guard{
    std::thread& t;
public:
    explicit thread_guard(std::thread& t_):t(t_){  }
    ~thread_guard(){
        if(t.joinable()){
            t.join();
        }
    }
    thread_guard(const thread_guard&)=delete;
    thread_guard& operator=(thread_guard const&)=delete;
};

struct func{
    int &i;
    func(int& i_):i(i_){  }
    void operator()(){
        for(unsigned j = 0;j < 1000000;++j){
            hello();
        }
    }
};

void f(){
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread t(my_func);
    thread_guard g(t);

    hello();
}


int main()
{
    f();
}

