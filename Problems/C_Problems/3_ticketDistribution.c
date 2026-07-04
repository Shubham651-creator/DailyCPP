// John has N friend and M different types of tickets available.
// Each friend 'i' including John (N+1 people) posssess some ticket which represent non-negative int ticket[i].

// The value of last index of ticket denotes John's tickets.

// Out of N friends John has, count the number of friends whose binary representation of their tickets differ 
// with binary representation of John's ticket by at most 'k' integer.

#include<stdio.h>

int intoBinary(int ticket){

    int count = 0;
    while(ticket > 0){
        //count the 1's
        if(ticket%2 != 0) count++;
        ticket /= 2;
    }
    return count;
}

int distribution(int n, int m, int k, int ticket[]){

    int countOne[m], count = 0; // store the difference
    for(int i=0; i<m; i++) countOne[i] = intoBinary(ticket[i]);

    //last index is john's binary count
    int john = countOne[m-1];

    for(int i=0; i<m-1; i++){
        int d = john - countOne[i];
        if(d < k) count++;
    }
    return count;
}

int main(){

    int N = 2; //Number of friends
    int M = 3; //different types of ticket available
    int k = 2; //want our bit difference is less than k
    int ticket[] = {5,6,7};

    printf("Enter N, M and k = \n");
    scanf("%d%d%d",&N,&M,&k);

    int count = distribution(N,M, k, ticket);

    printf("The count of ticket distribution is %d\n",count);
    return 0;
}