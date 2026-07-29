#include <iostream>
#include <stack>
#include <thread>
#include <mutex>

class ThreadSafeStack
{
private:
    std::stack<int> m_stack;
    mutable std::mutex m_mutex;

public:
    ThreadSafeStack() = default;

    // Disable copy operations
    ThreadSafeStack(const ThreadSafeStack&) = delete;
    ThreadSafeStack& operator=(const ThreadSafeStack&) = delete;

    // Move operations
    ThreadSafeStack(ThreadSafeStack&&) = default;
    ThreadSafeStack& operator=(ThreadSafeStack&&) = default;

    // Push
    void push(int value)
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_stack.push(value);

        std::cout << "Pushed : " << value << '\n';
    }

    // Pop
    bool pop(int& value)
    {
        std::lock_guard<std::mutex> lock(m_mutex);

        if (m_stack.empty())
            return false;

        value = m_stack.top();
        m_stack.pop();

        return true;
    }

    // Top
    bool top(int& value) const
    {
        std::lock_guard<std::mutex> lock(m_mutex);

        if (m_stack.empty())
            return false;

        value = m_stack.top();
        return true;
    }

    bool empty() const
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_stack.empty();
    }

    size_t size() const
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_stack.size();
    }
};

//------------------------------------------------------------

ThreadSafeStack ts;

void producer()
{
    for (int i = 1; i <= 5; i++)
    {
        ts.push(i * 10);
    }
}

void consumer()
{
    int value;

    for (int i = 0; i < 5; i++)
    {
        if (ts.pop(value))
            std::cout << "Popped : " << value << '\n';
        else
            std::cout << "Stack Empty\n";
    }
}

int main()
{
    std::thread t1(producer);
    std::thread t2(consumer);

    t1.join();
    t2.join();

    std::cout << "\nRemaining Size : " << ts.size() << '\n';

    return 0;
}