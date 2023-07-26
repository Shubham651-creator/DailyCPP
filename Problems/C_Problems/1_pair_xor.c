//your task is find and count the good integer in an array
//A Z is said to be good integer if and only if there exist two different +ve int X and Y 
//such that X^Y = Z and X&Y=0.

#include<stdio.h>
#include<math.h>
int main(){

    int n,count=0, duplicate=1;
    int a[] = {91,91,91,91,0};
    n= sizeof(a)/sizeof(a[0]);

    for(int k=0; k<n; k++){
        for(int i=1; i<a[k]; i++){
            for(int j=1; j<a[k]; j++){
                if(i!=j){ 
                    int xor = i^j;
                    int and = i&j;
                    if(xor==a[k] && and==0){
                        count++;
                        printf("count = %d\n",count);
                        printf("i^j=%d\t i&j=%d\n",i^j, i&j);
                        printf("i=%d\t j=%d\n",i, j);
                    }
                    
                }
            } 
        }
        if(a[k]==a[k+1]) duplicate++;
    }
    count/=2;
    printf("the duplicate = %d\n",duplicate);
    printf("A count of good integer is %d\n",count/duplicate);
    
    return 0;
}