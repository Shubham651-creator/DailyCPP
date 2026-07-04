//You are given two integer N and K
//Your task is print the smallest possible good integer
//An integer is said to be good integer if and only if it's greater than K,
//and it can otained by deleting zero or more digit from N without changing actual sequence of digits.

#include<stdio.h>

int closestLargest(int n, int k){

    int rem, r[4], i=3;

    while(n>0){
        rem = n%10;
        n/=10;
        r[i] = rem; i--;
        //printf("rem=%d\n",rem);
    }

    for(int j=0; j<4; j++){
        printf("rem[%d]=%d\n",j,r[j]);
    }
    
    int mx = r[0],store;

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(k < mx && ) {
                store = mx;
            }else{
                mx = r[i] * 10 + r[j+1];
            }
        }
    }
}

int main(){

    int n = 7195, k=11;
    int num = closestLargest(n, k);

    printf("The closest largest number is %d\n",num);
    return 0;
}
