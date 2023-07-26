#include <iostream>
#include <cstring>

// how to represent data for real world entity in C?
// structure

struct Employee
{
    int empid;
    int salary;
    char name[20];
} e2; // global struct variable

int main()
{

    struct Employee e1;
    // e1.name = "shuba"; //name is const pointer
    strcpy(e1.name, "shuba");

    typedef struct Employee EMP;
    EMP e2; // local struct variable

    return 0;
}