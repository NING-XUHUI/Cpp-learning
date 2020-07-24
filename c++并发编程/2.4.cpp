#include <iostream>
#include <thread>
using namespace std;

template<typename Iterater,typename T>
struct accumulate_block
{
    void operator ()(Iterater first,Iterater last,T& result)
    {
        result = std::accumulate(first,last,result);
    }
};

template<typename Iterrator,typename T>
T parallel_accumulate(Iterrator first,Iterrator last,T init)
{
    unsigned long const length = std::distance(first,last);
    if(!length)
        return init;
    unsigned long const min_per_thread=25;
    unsigned long const max_threads = (length+min_per_thread-1)/min_per_thread;

    unsigned long const hardware_threads = std::thread::hardware_concurrency();
    unsigned long const num_threads = std::min(hardware_threads!=0?hardware_threads:2,max_threads);
    unsigned long const block_size = length/num_threads;
    std::vector<T> results(num_threads);
    std::vector<std::thread> threads(num_threads-1);

    Iterrator block_start = first;
    for(unsigned long i = 0;i < (num_threads-1);i++)
    {
        Iterrator block_end=block_start;
        std::advance(block_end,block_size);
        threads[i] = std::thread(accumulate_block<Iterrator,T>(),block_start,block_end,std::ref(results[i]));
        block_start = block_end;
    }
    accumulate_block<Iterrator,T>()(block_start,last,results[num_threads-1]);
    std::for_each(threads.begin(),threads.end(),std::mem_fn(&std::thread::join);
}
int main()
{
    return 0;
}

