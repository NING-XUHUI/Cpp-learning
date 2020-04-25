#include <future>
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

int mythread()
{
    cout << "mythread()start "
         << "thread_id :" << std::this_thread::get_id() << endl;
    std::chrono::milliseconds dura(5000);
    std::this_thread::sleep_for(dura);
    cout << "mtthread()end "
         << "thread_id :" << std::this_thread::get_id() << endl;
    return 5;
}

int main(int argc, char const *argv[])
{
    // std::future的其他函数

    cout << "main"
         << " thread_id :" << std::this_thread::get_id() << endl;
    std::future<int> result = std::async(mythread);
    cout << result.get() << endl;
    cout << "NB" << endl;
    return 0;
}
