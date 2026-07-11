//return second largest element from a array
#include<stdio.h>
int secondLargest(int *a, int size){
    //find the largest element
    int large = a[0], secLarge=0;
    for(int i=0; i<size; i++){
        //printf("%d\t%d\n",a[i],size);
        if(large < a[i]) large = a[i];
    }

    //now, check second largest ele by excluding largest ele
    for(int i=0; i<size; i++){
        if(large != a[i]){
            if(secLarge < a[i]) secLarge = a[i];
        }
    }
    
    return (secLarge==0 ? -1: secLarge);
}
int main(){

    int a[] ={61,30, 28, 47, 42, 25, 41, 56, 27, 45, 44, 
        34, 46, 35, 58, 36, 60, 29, 53, 55, 32, 31, 33, 
        59, 50 ,51 ,52 ,37 ,39 ,38 ,43 ,49 ,54 ,57, 40, 26, 48};
    int size = sizeof(a) / sizeof(a[0]);
    int ele = secondLargest(&a[0], size);
    printf("second largest element is %d\n",ele);
    return 0;
}