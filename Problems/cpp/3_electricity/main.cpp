#include <iostream>

#include "Electricity.h"

int main()
{
    Electricity *e = new Electricity;
    e->accept();
    e->display();

    Water w;
    w.accept();
    w.display();

    delete e;
}