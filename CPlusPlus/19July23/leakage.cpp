#include<iostream>
#include<bits/stdc++.h>

void display(){

    static int y;
    ++y;

    int* p = (int *) malloc (sizeof(int)*5); //use 'free(p)' to free memeory on heap

    //int *p=  new int[5]; //use 'delete[]p' to free memeory from heap

    std::cout<<" Enter the elements : ";
    for(int i=0; i<5; i++){
        std::cin>> p[i];
    }
    for(int i=0; i<5; i++){
        std::cout<<p[i]<<std::endl;
    }
    free(p);
    //delete[]p; //otherwise it's memory leakage problem
}

int main(){

    static int m; //store in 'Data Section' memory

    display();
    return 0;
}