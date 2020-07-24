#include <iostream>
#include <thread>
#include <vector>
using namespace std;

void do_work(unsigned id);
void f(){
    std::vector<std::thread> threads;
    for(unsigned i = 0;i< 20;i++){              // 生成一批线程
        threads.push_back(std::thread(do_work,i));
    }
    std::for_each(threads.begin(),threads.end(),std::mem_fn(&std::thread::join()));   // 等待所有线程
}

int main()
{
    return 0;
}

