#include <iostream>
#include <mutex>
#include <thread>

std::shared_ptr<some_resource> resource_ptr;
void foo()
{
    if(!resource_ptr)
    {
        resource_ptr.reser(new some_resource);              // 需要保护的部分（初始化）
    }
    resource_ptr->do_something();
}

std::shared_ptr<some_resource> resource_ptr1;
std::mutex resource_mutex;

void foo1()
{
    std::unique_lock<std::mutex> lk(resource_mutex);
    if(!resource_ptr)
    {
        resource_ptr.reset(new some_resource);
    }
    lk.unlock();
    resource_ptr->do_something();
}


void undefined_behaviour_with_double_checked_locking()          // 二次检查锁定
{
    if(!resource_ptr){
        std::lock_guard<std::mutex> lk(resource_mutex);
        if(!resource_ptr)
        {
            resource_ptr.reset(new some_resource);
        }
    }
    resource_ptr->do_something();
}


int main()
{
    return 0;
}

