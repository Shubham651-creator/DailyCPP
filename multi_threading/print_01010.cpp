/*
    Print 01010101010101....
    using 2 threads
*/

#include<iostream>
#include<mutex>
#include<thread>
#include<condition_variable>

std::mutex mt;
std::condition_variable cv;

bool turnZero = false;
int count = 50;

void printZero(){
    for(int i=0; i<count; ++i){
        std::unique_lock<std::mutex> lock(mt);

        cv.wait(lock, [](){
            return !turnZero;
        });

        std::cout<< "0";
        turnZero = true;

        cv.notify_one();
    }
};

void printOne(){
    for(int i=0; i<count; ++i){
        std::unique_lock<std::mutex> lock(mt);

        cv.wait(lock, [](){
            return turnZero;
        });

        std::cout<< "1";
        turnZero = false;

        cv.notify_one();
    }
};

int main(){

    std::thread t0(printZero);
    std::thread t1(printOne);

    t0.join();
    t1.join();
}