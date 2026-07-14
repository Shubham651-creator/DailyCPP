#include<iostream>

class top{
    public:
    void display(){
        std::cout<< "You are in top\n";
    };
};

class underTop: public top{
public:
    void display(){
        std::cout<< "You are in undertop\n";
    }
};

class derived1: public underTop{
public:
void display(){
        std::cout<< "You are in derived1\n";
    }
};

class derived2: public underTop{
public:
void display(){
        std::cout<< "You are in derived2\n";
    }
};

class child: public derived1, public derived2{
public:
void display(){ 
        std::cout<< "You are in child\n";
        derived1::display();
        derived2::display();
    }
};
int main(){

    child c1;
    c1.display();

    return 0;
 
}