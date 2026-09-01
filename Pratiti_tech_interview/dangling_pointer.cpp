#include<iostream>

int main(){

    int *m = (int*)malloc(sizeof(int));
    int a = 20;
    int *p = new int(a); // allocation of heap to use Delete

    std::cout<< "p = " << p << "\nvalue = " << *p << std::endl;

    delete p;
    free(m);
    // p = nullptr;

    std::cout<< "p = " << p << "\nvalue = " << *p << std::endl;

    return 0;
}