#include<iostream>

class Singleton{
    private:
        // static Singleton* instance;
        Singleton() = default;

    public:
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;
        
        static Singleton& getInstance(){
            static Singleton instance;
            return instance;
        }

        void display(){
            std::cout<<"Singleton instance: "
            << &Singleton::getInstance() << std::endl;
        }

};

int main(){

    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();

    // Singleton* s3 = new Singleton(); //inaccessible
 
    s1.display();
    s2.display();
}