#include <iostream>
#include "One.h"

void One::display()
{
    std::cout << "a = " << a
              << "\tstr = " << str
              << "\n";
}
 
void operator<<(std::ostream &out, One &one)
{
    one.display();
}
