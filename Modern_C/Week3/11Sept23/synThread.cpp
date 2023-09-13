#include <thread>
#include <iostream>

/*
    Sync thread :

    - thread is lightweight process. Idea is achieve parallelism by dividing
    a process into multiple threads.

    e.g.
    1. The browser has multiple tabs that can be different threads.
    2. In MS word, One thread to format the text, another thread to process
    input(spell checker).
    3. VS code's Intellicence
*/

int factorial(int n)
{
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    int n;
    std::cout << "Enter number:\n";
    std::cin >> n;

    std::thread f1(factorial, n);
    std::thread f2([](int n)
                   { 
                        std::this_thread::sleep_for(std::chrono::seconds(5));
                        return n * n; },
                   9);

    f1.join();
    f2.join();
}