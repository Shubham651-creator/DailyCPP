#include <iostream>

int main()
{
    int n1 = 10;
    int &n2 = n1;

    int& n3 = n2;

    int *ptr = &n1;
    int *&refPtr = ptr;

    // array of reference cannot be created
    // int& arr[2]{n1}; //compiler-time error

    // reference cannot be stored in container

    // reference to reference DON'T WORK AS EXPECTED !!  
    
    n1 = 100;
    n2 = 2;
    n3 = 3;

    std::cout<<n1<<"\n";
}