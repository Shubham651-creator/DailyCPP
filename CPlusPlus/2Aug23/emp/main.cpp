#include<iostream>
#include"Emp.h"


int main(){

    Emp *e = new Emp();
    e->accept();
    e->display();
    e->calculateTotalSalary();
    
    return 0;
}