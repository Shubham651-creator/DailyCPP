#include<iostream>
#include<thread>
using namespace std;

//Singleton design Pattern
class Singleton{
    private:
        static Singleton* instance;

        Singleton(){
            cout<<"Singleton default private constructor called"<< endl;
        }

    public:

        static Singleton *getInstance(){
            if(instance == nullptr){
                instance = new Singleton();
            }
            return instance;
        }

        static void destroy(){
            delete instance;
            instance = nullptr;
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

    Singleton* s1 = Singleton::getInstance();
    s1->display();
    
    // with threads safe
    thread t1(worker);
    thread t2(worker);
    thread t3([](){
        Singleton::getInstance()->display();
    });

    t1.join();
    t2.join();
    t3.join();

    Singleton::getInstance()->destroy();
}