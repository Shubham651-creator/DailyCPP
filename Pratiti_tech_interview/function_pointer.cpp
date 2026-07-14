#include<iostream>
#include<functional>

int add(int a, int b){
    return a+b;
}

int main(){

    // Raw functional pointer
    int (*fun) (int,int) = &add;
    int sum = fun(10,20);
    std::cout<< sum;

    // Modern functional pointer
    std::function<int(int,int)> f = &add;
    std::cout<< f(20,30);

    return 0;
}