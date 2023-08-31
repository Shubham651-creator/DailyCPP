// Threading

/*
    1. Commands to the compile:
    > g++ -lpthread Threading.cpp -o Threading

    ----------------------------------------------------------
    2. command to run and check time
    > time ./Threaing

    ----------------------------------------------------------
    3. Multi-threading:
    > g++ Threading.cpp -lpthread -o Threading
or  > g++ -pthread Threading.cpp -o Threading

------------------------------------------------------------
    4. Where to see total time?
     - for Ubantu : real time

    -----------------------------------------------------------
    5.  I sometimes get squre output first and sometimes cube
    even though I run the exact same code?
    -> It it normal.(Race Condition Issues*) .Threads execute in
    any order OS Wants!

*/

#include <iostream>
#include <thread>

void square(int number)
{
    std::this_thread::sleep_for(std::chrono::seconds(5)); // delay by 5 sec
    std::cout << number * number << '\n';
}

void cube(int number)
{
    std::this_thread::sleep_for(std::chrono::seconds(5)); // delay by 5 sec
    std::cout << number * number * number << '\n';
}

int main()
{
    std::thread t1(&square, 10);
    std::thread t2(&cube, 10);

    t1.join(); // join : wait for thread to execute
    t2.join();
}