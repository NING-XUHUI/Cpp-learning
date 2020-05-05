/**
* @file thread_pool.h
* @brief 
* @details
* @date 2020/4/28 12:06 上午
* Created by 宁旭晖 on 2020/4/28.
*/
#pragma onceonce
#ifndef THREADPOOL_THREAD_POOL_H
#define THREADPOOL_THREAD_POOL_H
#include <atomic>
#include <condition_variable>
#include <functional>
#include <future>
#include <queue>
#include <stdexcept>
#include <thread>
#include <vector>

namespace std {
#define MAX_THREAD_NUM 256
    class threadpool {
        using Task = std::function<void()>;
        //线程池
        std::vector<std::thread> pool;
        //任务队列Ò
        std::queue<Task> tasks;
        //同步锁
        std::mutex m_lock;
        //条件阻塞
        std::condition_variable cv_task;
        //是否关闭提交
        std::atomic<bool> stopped;
        //空闲线程数量
        std::atomic<int> idlThrNum;

    public:
        inline threadpool(unsigned short size = 4) : stopped(false) {
            idlThrNum = size < 1 ? 1 : size;
            for (size = 0; size < idlThrNum; size++) {
                //初始化线程数量
                pool.emplace_back(
                        [this] {
                            while (!this->stopped) {
                                std::function<void()> task;
                                {
                                    std::unique_lock<std::mutex> lock{this->m_lock};
                                    this->cv_task.wait(lock,
                                                       [this] {
                                                           return this->stopped.load() || this->tasks.empty();
                                                       });
                                    if (this->stopped && this->tasks.empty())
                                        return;
                                    task = std::move(this->tasks.front());
                                    this->tasks.pop();
                                }
                                idlThrNum--;
                                task();
                                idlThrNum++;
                            }
                        });
            }
        }
        inline ~threadpool() {
            stopped.store(true);
            cv_task.notify_all();
            for (std::thread &thread : pool) {
                if (thread.joinable())
                    thread.join();
            }
        }

    public:
        template<class F, class... Args>
        auto commit(F &&f, Args &&... args) -> std::future<decltype(f(args...))> {
            if (stopped.load())// stop == true ??
                throw std::runtime_error("commit on ThreadPool is stopped.");

            using RetType = decltype(f(args...));// typename std::result_of<F(Args...)>::type, 函数 f 的返回值类型
            auto task = std::make_shared<std::packaged_task<RetType()>>(
                    std::bind(std::forward<F>(f), std::forward<Args>(args)...));// wtf !
            std::future<RetType> future = task->get_future();
            {                                            // 添加任务到队列
                std::lock_guard<std::mutex> lock{m_lock};//对当前块的语句加锁 lock_guard 是 mutex 的 stack 封装类，构造的时候 lock()，析构的时候 unlock()
                tasks.emplace(
                        [task]() {// push(Task{...})
                            (*task)();
                        });
            }
            cv_task.notify_one();// 唤醒一个线程执行
            return future;
        }
        //空闲线程数量
        int idlCount() { return idlThrNum; }
    };
}// namespace std
#endif//THREADPOOL_THREAD_POOL_H
