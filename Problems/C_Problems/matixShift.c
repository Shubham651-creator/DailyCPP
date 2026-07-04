//Given an array p[ 5 ], write a function to shift it circularly left by two
// positions. Thus, if the original array is { 15, 30, 28, 19, 61 } then after
// shifting it will be { 28, 19, 61, 15, 30 } Call this function for a 4 x 5
// matrix and get its rows left shifted.

#include<stdio.h>

int* rotate(int *n){
    static int a[4][5] ={ 
        {15, 30, 28, 19, 61},
        {1, 3, 8, 9, 6},
        {66, 55, 2, 8, 1},
        {95, 34, 98, 49, 60},
     };
    
    //*n = 4*5 = 20
    *n = sizeof(a)/sizeof(a[0][0]); 

    static int t[4][5] ;
    for(int j=0; j<4; j++){
        for(int i=0; i<3; i++){
        t[j][i] = a[j][i+2];
        }
        for(int i=3; i<5; i++){
            t[j][i] = a[j][i-3];
        }
    }
    
    return *t;
}
int main(){
    
    int *size;
    int* m  = rotate(size);
    for(int i=1; i< *size+1; i++){
            printf("%d\t",*(m+i-1));
            if(i%5 == 0) printf("\n");
    }
    printf("\n");
    
    return 0;
}