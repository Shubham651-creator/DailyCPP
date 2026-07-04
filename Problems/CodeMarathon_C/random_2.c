#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){ 

    //5 random questions
    int a1,a2,a3,a4,a5;
    int correct =0 , incorrect = 0;
    for(int i=0; i<5; i++){
        int a = rand()/20000000;
        int b = rand()/100000000;

        switch (i)
        {
        case 0:
            printf("1. What is %d + %d?", a,b);
            scanf("%d",&a1);
            if(a+b == a1) {printf("correct!"); correct++;}
            else{ printf("incorrect!"); incorrect++;}
            break;
        case 1:
            printf("1. What is %d + %d?\n", a,b);
            scanf("%d",&a2);
            if(a+b == a2) {printf("correct!"); correct++;}
            else {printf("incorrect!"); incorrect++;}
            break;
        case 2:
            printf("1. What is %d - %d?\n", a,b);
            scanf("%d",&a3);
            if(a-b == a3) {printf("correct!");correct++;}
            else {printf("incorrect!"); incorrect++;}
            break;
        case 3:
            printf("1. What is %d + %d?\n", a,b);
            scanf("%d",&a4);
            if(a+b == a4) {printf("correct!"); correct++;}
            else {printf("incorrect!");incorrect++;}
            break;
        case 4:
            printf("1. What is %d - %d?\n", a,b);
            scanf("%d",&a5);
            if(a- b == a5) {printf("correct!"); correct++;}
            else{
                printf("incorrect\n");
                incorrect++;
            }
            break;
        
        default:
            break;
        }
    }

    //summary
    printf("the total questions = 5\n");
    printf("the correct = %d\n",correct);
    printf("the incorrect = %d\n",incorrect);
    return 0;
}