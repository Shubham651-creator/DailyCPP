#ifndef ONE_H
#define ONE_H

#include <iostream>

class One
{
private:
    int a;
    std::string str;

public:
    One()
    {
        a = 10;
        str = "subham";
    }
    One(int aVar, std::string strVar)
        : a(aVar), str(strVar)
    {
    }
    ~One(){
        
    }

    void display();

     friend void operator<<(std::ostream &out, One &one);
};

#endif // ONE_H
