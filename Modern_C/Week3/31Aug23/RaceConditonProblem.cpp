#include <iostream>
#include <thread>
#include <mutex>

/*
    Bash command :

    > g++ -pthread RaceConditionProblem.cpp -o app
    > for((i=0;i<100;i++));do ./app; done

    After compiler this command, you get different ouput

    To solve this Race Condition problem:
    1. lock less
    2. lock based syn mechnisms

*/

std::mutex mt;

int amount = 1000;

void withdraw()
{
    for (int i = 0; i < 100; i++)
    {
        std::this_thread::sleep_for(std::chrono::microseconds(10));

        mt.lock();
        // critical section
        amount -= 10;
        mt.unlock();
    }
}

void deposite()
{
    for (int i = 0; i < 100; i++)
    {
        std::this_thread::sleep_for(std::chrono::microseconds(10));

        mt.lock();
        // critical section
        amount += 10;
        mt.unlock();
    }
}

int main()
{
    std::thread t1(&withdraw);
    std::thread t2(&deposite);

    t1.join();
    t2.join();

    std::cout << "final amount : " << amount << "\n";
}

/*

    t2 starts

    amount = 1000[RAM] -----> ALU [  1000-10 =990    ]

    t1 starts

    amount = 990 [RAM] ------> ALU [  1000+10 = 1010  ]
            [1010]        <----------


                        OR

    t1 starts

    amount = 1000[RAM] -----> ALU [   1000+10 =1010   ]

    t2 starts

    amount = 1010 [RAM] ------> ALU [  1000-10 = 990  ]
            [990]        <----------

*/
