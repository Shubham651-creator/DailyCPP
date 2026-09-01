#include <iostream>
#include <vector>
#include <thread>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>

class ThreadPool
{
private:

    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex queueMutex;
    std::condition_variable condition;

    bool stop = false;

public:

    // Consumer
    ThreadPool(size_t numThreads)
    {
        for (size_t i = 0; i < numThreads; ++i)
        {
            workers.emplace_back([this]()
            {
                while (true)
                {
                    std::function<void()> task;

                    {
                        std::unique_lock<std::mutex> lock(queueMutex);

                        condition.wait(lock, [this]()
                        {
                            return stop || !tasks.empty();
                        });

                        if (stop && tasks.empty())
                        {
                            return;
                        }

                        task = std::move(tasks.front());
                        tasks.pop();
                    }

                    task();
                }
            });
        }
    }

    // Producer
    void enqueue(std::function<void()> task)
    {
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            if (stop)
            {
                throw std::runtime_error("ThreadPool stopped");
            }
            tasks.push(std::move(task));
        }

        condition.notify_one();
    }

    ~ThreadPool()
    {
        {
            std::lock_guard<std::mutex> lock(queueMutex);
            stop = true;
        }

        condition.notify_all();

        for (auto& worker : workers)
        {
            worker.join();
        }
    }
};

int main()
{
    ThreadPool pool(3);

    for(int i = 0; i < 100; ++i)
    {
        pool.enqueue([i]()
        {
            std::cout
                << "Executing task "
                << i
                << " on thread "
                << std::this_thread::get_id()
                << '\n';
        });

        pool.enqueue([i](){ 
            std::cout << "More added " << i+100 
                << "on thread " 
                << std::this_thread::get_id()<<'\n';
        });
    }

    return 0;
}