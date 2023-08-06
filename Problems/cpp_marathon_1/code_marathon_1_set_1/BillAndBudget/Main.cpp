#include<iostream>
#include"Electricity.h"

int main(){

    Electricity* electricity = new Electricity[5];

    electricity[0].accept();
    electricity[0].display();
    return 0;
}