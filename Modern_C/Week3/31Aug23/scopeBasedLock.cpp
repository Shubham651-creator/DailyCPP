#include <iostream>
#include <thread>
#include <mutex>

// lock-scope based : lock gurad
// It unlock the resoruce at end of scope.
// it is not much optimized method

/*
    Bash command :

    > g++ -pthread RaceConditionProblem.cpp -o app
    > for((i=0;i<100;i++));do ./app; done
*/

std::mutex mt;

int amount = 1000;

void withdraw() // t1 thread
{
    for (int i = 0; i < 100; i++)
    {
        std::this_thread::sleep_for(std::chrono::microseconds(10));

        std::lock_guard<std::mutex> lk(mt); // gurad lock
        // critical section
        amount -= 10;
        std::cout << "square\n";
    }
}

void deposite() // t2 thread
{
    for (int i = 0; i < 100; i++)
    {
        std::this_thread::sleep_for(std::chrono::microseconds(10));

        std::lock_guard<std::mutex> lk(mt); // gurad lock
        // critical section
        amount += 10;
        std::cout << "cube\n";
    }
}

int main() // main thread container two more independent thread t1 & t2.
{
    // we are mapping a function to thread object.
    // and it is only declaration, NOT a calling a function.
    std::thread t1(&withdraw);
    std::thread t2(&deposite);

    // the main thread now block state, and wait for termination
    // of t1 and t2 threads.
    t1.join();
    t2.join();

    std::cout << "final amount : " << amount << "\n";
}
