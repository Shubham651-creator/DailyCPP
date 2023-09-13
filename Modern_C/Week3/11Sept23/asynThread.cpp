/*
    Async Execution : (future promise model)

    - Switching the activity on same thread(one thread).

    - One thread is running in background, and you work at time
    on another thread.
*/

#include <thread>
#include <iostream>
#include <future>

int operation(std::future<int>& data)
{
    // square function : independent
    auto f1 = [](int number)
    {
        std::this_thread::sleep_for(std::chrono::seconds(5));
        std::cout << "Square of given number " << number
                  << " is :" << number * number << "\n";
    };

    f1(29); // independent function call

    // factorial function : dependent on N
    int value = data.get();
    if (value < 0)
    {
        throw std::runtime_error("Can't find factorial for negative number\n");
    }
    else if (value == 0 || value == 1)
    {
        return 1;
    }
    else
    {
        int result = 1;
        for (int i = 2; i <= value; i++)
        {
            result *= i;
        }
        return result;
    }
}

int main()
{
    int N;

    std::promise<int> pr; // make a promise

    std::future<int> data = pr.get_future(); // set up a channel between promise and future

    std::future<int> result =
        std::async(std::launch::async, operation, std::ref(data)); // throw the future accross the chennal attached to operation

    std::cout << "Number Bhej bhai,...late ho raha hai\n";
    std::cin >> N;

    // fulfill promise
    pr.set_value(N);

    // wait 
    std::cout<<"If anwser is ready, it should be printed here\n"
    << result.get()<<'\n';
}

/*
    [promise]                     [future]

                CHANNEL
        --------------------------
    input ---->                 ---> output
        --------------------------
*/