#include <iostream>
#include <thread>
#include <mutex>

std::shared_ptr<some_resource> resource_ptr;
std::once_flag resource_flag;

void init_resource()
{
    resource_ptr.reset(new some_resource);
}

void foo()
{
    std::call_once(resource_flag,init_resource);            // 初始化被正好调用一次
    resource_ptr->do_something();
}

int main()
{
    return 0;
}

