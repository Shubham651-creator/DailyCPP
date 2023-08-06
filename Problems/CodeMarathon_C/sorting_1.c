#include<stdio.h>

void first_digit(int rem){
    switch (rem)
     { 
        case 1:printf(" one "); break;
        case 2: printf(" two "); break;
        case 3: printf(" Three"); break;
        case 4: printf(" four "); break;
        case 5: printf(" five "); break;
        case 6: printf(" six "); break;
        case 7: printf(" seven "); break;
        case 8: printf(" eight "); break;
        case 9: printf(" nine ");break;
                    
        default: break;
    }           
}

void second_digit(int rem){
    switch (rem)
                {
                    case 10: printf( " Ten ");break;
                    case 11:printf(" Eleven ");break;
                    case 12 : printf(" twele ");break;
                    case 13:printf(" thirteen ");break;
                    case 14 : printf(" fourteen ");break;
                    case 16:printf(" sixteen ");break;
                    case 15 : printf("Fifteen ");break;
                    case 17:printf(" seventeen ");break;
                    case 18 : printf(" eighten ");break;
                    case 19:printf(" nineteen ");break;
                    case 20 : printf(" twenty ");break;
                    case 30 : printf(" thirty ");break;
                    case 40 : printf(" fourty ");break;
                    case 50 : printf(" fifty ");break;
                    case 60 : printf(" sixty ");break;
                    case 70 : printf(" seventy ");break;
                    case 80 : printf(" eighty ");break;
                    case 90: printf(" ninety ");
                    
                    default:
                        break;
                }
}

void third_digit(int n){

    int ele = n, rev[3], i=0;
    while(n>0){
        int rem = n%10;
        rev[i++]=rem;
        n/=10;
    }
    first_digit(rev[2]);
    printf(" hundred ");
    second_digit( rev[1]*10);
    first_digit(rev[0]);

    printf("\n");
}

void fourth_digit(int n){
    int ele = n, rev[4], i=0;
    while(n>0){
        int rem = n%10;
        rev[i++]=rem;
        n/=10;
    }
    // for(int i=0; i<4; i++){
    //     printf("%d",rev[i]);
    // }
    first_digit(rev[3]);
    printf(" thousand ");
    first_digit(rev[2]);
    printf(" hundred ");
    second_digit( rev[1]*10);
    first_digit(rev[0]);

    printf("\n");
}

void five_digit(int n){
    int ele = n, rev[5], i=0;
    while(n>0){
        int rem = n%10;
        rev[i++]=rem;
        n/=10;
    }
    second_digit(rev[4]*10);
    first_digit(rev[3]);
    printf(" thousand ");
    first_digit(rev[2]);
    printf(" hundred ");
    second_digit( rev[1]*10);
    first_digit(rev[0]);

    printf("\n");
}

int main(){
    
    //array contains unique numbers upto 5 
    int a[5]={55555,5264,300,18,0};
    //int a[5];

    for(int i=0; i<5; i++){
        //scanf("%d",&a[i]);
        //printf("%d\t",a[i]);
    }

    // for(int i=0; i<5; i++){
    //     printf("%d\t",a[i]);
    // }
    printf("\n");

    //sorting descending
    //max value first
    int t;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(a[i] > a[j]){
                //swap the element
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }

    int count[5]={0};
    for(int i=0; i<5; i++){

        int x= a[i];
        printf("%d\n",a[i]);
        
            // if(x == 100) printf(" one hundred \n"); break;
            // if(x == 1000) printf("one thousand\n");break;
            // if( x == 10000) printf(" Ten thousand\n");break;

        while(x>0){
            count[i]++;
            x/=10;
        }
        if(count[i]==1) first_digit(a[i]);
        if(count[i]==2) second_digit(a[i]); 
        if(count[i]==3) third_digit(a[i]);
        if(count[i]==4) fourth_digit(a[i]); 
        if(count[i]==5) five_digit(a[i]);
        
    }

    //base case
    for(int i=0; i<5; i++){
        //printf("%d\n",a[i]);
        if(a[i]==0) printf("\nzero\n");
    }

    return 0;
}