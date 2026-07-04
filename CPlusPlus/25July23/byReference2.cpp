#include <iostream>

int a[5] = {1, 2, 3, 4, 5};

int& fun()
{
    return a[2]; // returns reference to memory of a[2]
}
int main()
{
    //it only works for reference & machnism
    fun() = 98; // a[2]= 98

    int b = fun();
    std::cout << "the value of b = " << b << "\n";

    for(int i=0; i<5; i++){
        std::cout<<a[i]<<"\n";
    }

    return 0;
}