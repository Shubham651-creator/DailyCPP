//find the max sum of contiguous subarray of size k

#include<stdio.h>

int maxSubarraySum(int a[], int n, int k){
    //base case
    if(n<k) return -1;

    int mx = 0;
    for(int i=0; i<n-3; i++){
        for(int j=i; j<k+i; j++ ){
            if(mx < a[j]+a[j+1]+a[j+2]){
                mx = a[j]+a[j+1]+a[j+2];
                //printf("%d",mx);
            }
        }
    }
    printf("the max is %d\n",mx);
    return mx;
}

int main(){

    int size=6 ;
    int a[size],k=3;

    printf("Enter the array size= ");
    scanf("%d",&size);

    printf("Enter subarray size k = ");
    scanf("%d",&k);

    printf("Enter the array elements = \n");
    for(int i=0; i<size; i++){
        scanf("%d",&a[i]);
    }

    int maxEle = maxSubarraySum(a, size, k);

    printf("The max is %d\n",maxEle);
    return 0;
}