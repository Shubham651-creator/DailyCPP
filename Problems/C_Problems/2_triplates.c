// Given 3 int array namely A,B and C.
// using array you have to create a triplates by taking one int from every array.
// Perform an Xor operation on every triplates and
// return the numbers of triplates that have even number of set bits.

#include<stdio.h>

int compute(int a[],int aSize, int b[],int bSize, int c[],int cSize){

    int n = aSize*bSize*cSize;
    int xor[n],itr =0 ;

    //stores all possible combination of triplate in array
    for(int i=0; i<aSize; i++){
        for(int j=0; j<bSize; j++){
            for(int k=0; k<cSize; k++){
                xor[itr++] = a[i]^b[j]^c[k];
            }
        }
    }

    //convert decimal element of xor array to binary
    int one=0, countEven = 0;
    for(int i=0; i<n; i++){
        int x = xor[i];

        while(x > 0){
            //count the 1's
            if(x%2!=0) one++;
            x/=2;
        }
         //increment if 'one' is even
        if(one%2==0) countEven++;
    } 
    return countEven; 
}

int main(){
    int aSize = 2, bSize = 1,  cSize = 2;
    int A[] = {1,2};
    int B[] ={3};
    int C[] = {2,3};

    int count = compute(A,aSize, B,bSize, C,cSize);
    printf("The count of even bit set is %d\n",count);

    return 0;
}