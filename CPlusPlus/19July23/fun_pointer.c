#include <stdio.h>

// we can not create function inside the stucture in C
//but the only option is function pointer

struct Employee
{
    int empid;
    int salary;
    char name[20];
} e2; // global struct variable

struct BankAcc
{

    // function pointer
    // declaration
    void (*ptr)(int amount); //(function_returnType) (*ptr) (dataType)
};

void deposit(int amount)
{
    printf("%d\n", amount);
}

int add(int a, int b)
{
    printf("%d + %d = ", a, b);
    return a + b;
}
int main()
{

    struct BankAcc b;

    // initalization of function pointer
    b.ptr = &deposit;
    b.ptr(200);

    // for add function
    int (*p)(int a, int b) = &add;
    int c = p(10, 20);
    printf("%d\n", c);

    return 0;
}