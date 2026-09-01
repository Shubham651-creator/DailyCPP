// C++ Program using Volatile Qualifier in Multithread
#include <chrono>
#include <iostream>
#include <thread>
using namespace std;

// Declare volatile variable
volatile bool data_ready = false;

void producer()
{
    // Simulate data production
    this_thread::sleep_for(chrono::microseconds(100));
    cout << "\nProducer: Data produced." << endl;

    // Signal data is ready
    data_ready = true;
}

void consumer()
{
    // Wait for data to become ready
    while (!data_ready) {
        // Spin-wait until data is ready (not recommended in
        // real scenarios)
        cout<<"Waiting..." <<endl;
    }
    // Once data is ready, consume it
    cout << "Consumer: Data consumed." << endl;
}

int main()
{
    // Create threads
    thread t1(producer);
    thread t2(consumer);

    // Join threads
    t1.join();
    t2.join();

    // Print completion message
    cout << "Main: All threads have finished execution."
         << endl;

    return 0;
}