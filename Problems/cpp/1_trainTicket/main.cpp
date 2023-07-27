#include <iostream> 
#include "Train.h"

//client code
int main()
{
    // creating array of 5 train objects
    Train train[5];
    int size = 5;

    // passing array of trains to showMenu funtion in file Train.cpp
    showMenu(train, size);
}