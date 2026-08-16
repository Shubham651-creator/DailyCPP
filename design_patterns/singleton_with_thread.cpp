#include<iostream>
#include<thread>
using namespace std;

//Singleton design Pattern
class Singleton{
    private:
        static Singleton* instance;

    public:
        Singleton(){
            cout<<"Singleton default constructor called"<< endl;
        }

        static Singleton *getInstance(){
            if(instance == nullptr){
                instance = new Singleton();
            }
            return instance;
        }

        void display(){
            cout<<"Called Display()" << endl;
        }
};

Singleton* Singleton::instance = nullptr;

void worker(){
    Singleton::getInstance()->display();
}

int main(){

    Singleton* s1 = new Singleton;
    s1->display();

    worker();
    
    // with threads safe
    thread t1(worker);
    thread t2(worker);

    t1.join();
    t2.join();
}