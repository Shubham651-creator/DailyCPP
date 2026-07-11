#include <stdio.h>

// array is constant pointer to non-constant dataType

void display(int arr[3])
{                                         // int *arr
    printf("display size of *arr=%ld\n", sizeof(arr)); // 8 bytes

    for (int i = 0; i < 3; i++)
    {
        // printf("%d\t",*arr+i); //*(arr+i)
        
        //print address of array element
        printf("%d\t", &arr[i]);
         

        //below code show similar working as above code
        printf("%d\t", *arr);
        ++arr;
    }
    printf("\n");

    int a = 10;
    int *p = &a;
    printf("p =%d\n", p);
    printf("*p=%d\n", *p);
    printf("&p = %d\n", &p);
    printf("++*p = %d\n", ++*p);

    printf("*p++ = %d\n", *p++); //*p and p++
    printf("p = %d\n", p);
    printf("&p = %d\n", &p);
    printf("*p = %d\n", *p);
}

int main()
{

    int arr[3] = {1, 2, 5}; // int *const(arr);
    int *p; 
    printf("main= %ld\n", sizeof(p)); // 4*30=120 bytes
    display(arr);

    // arr++; //

    return 0;
}