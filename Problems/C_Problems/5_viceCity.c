// There are infinity number of house from 0 to infinity with 1 person hiding each house.
// The thief hiding in the house M.
// The policeman begins his inspection from house N.

// If police is currently standing in front of some house k, then he can 
// go to (k+1)th or ((k+M/2)%M)th house from the kth house, in order to find thief.

// M >= N 

#include<stdio.h>

int viceCity(int n, int m){

    int count=0;
    int policePos = n, thiefPos = m;

    return count;
}

int main(){

    int N = 2, M = 4;
    //1. 2 -> 3-> 4
    //2. 2 -> 0-> 1-> 3-> 4

    //ouptut : 2

    int sequence = viceCity(N, M);

    printf("The posssible sequence is %d\n",sequence);
    return 0;
}