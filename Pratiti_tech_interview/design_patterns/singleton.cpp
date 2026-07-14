//write sington class code
#include <iostream>
class Singleton
{
private:
    static Singleton *instance;
    Singleton() {} // private constructor

public:
    static Singleton *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new Singleton();
        }
        return instance;
    }

    void display()
    {
        std::cout << "Singleton instance\n";
    }
};

Singleton *Singleton::instance = nullptr;

int main()
{
    Singleton *s1 = Singleton::getInstance();
    s1->display();

    Singleton *s2 = Singleton::getInstance();
    s2->display();

    if (s1 == s2)
    {
        std::cout << "Both instances are the same\n";
    }
    else
    {
        std::cout << "Instances are different\n";
    }

    return 0;
}