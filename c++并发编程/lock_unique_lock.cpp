#include <iostream>
#include <mutex>
#include <thread>

class some_big_object;
void swap(some_big_object& lhs,some_big_object& rhs);

class X{
private:
    some_big_object some_detail;
    std::mutex m;
public:
    X(some_big_object const& sd):some_detail(sd){}
    friend void swap(X& lhs,X& rhs)
    {
        if(&lhs==&rhs)
            return;
        std::unique_lock<std::mutex> lock_a(lhs.m,std::defer_lock); //defer_lock保留互斥元为未锁定
        std::unique_lock<std::mutex> lock_b(rhs.m,std::defer_lock);
        std::lock(lock_a,lock_b);                                   // 互斥元在这里被锁定
        swap(lhs.some_detail,rhs.some_detail);
    }
};

int main()
{
    return 0;
}

