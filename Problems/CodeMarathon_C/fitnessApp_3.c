#include<stdio.h>
#include<math.h>

typedef struct limits{

    int min ;
    int max ;
}limits;

int calculateTotalRewards(short unsigned min, short unsigned max){
    int diff = max - min;
    printf("Max = %d\nmin = %d\ndiff=%d\n",max,min,diff);
    int reward =0;
    
    if( diff <= 5){
        //sum of all numbers between min and max
        int mxSum = max*(max+1)/2; 
        int minSum = min*(min+1)/2; 

        reward = mxSum - minSum + min;
    }else{

         //if diff div by 5 and 7, then add 35 in reward
        if(diff%5==0 && diff%7==0) {
            reward +=35; 
            printf("5 and 7 = %d\n",reward);
            return reward;
        }

        if(diff%2!=0){ //odd num 
            if(diff%5==0) {
                reward *=5; 
                printf("5 = %d\n",reward);
                return reward;
            }     
        }

        if(diff%7==0) {
            reward+= (diff*diff);
            printf("7= %d\n",reward);
            return reward;
        }

        if(diff < 2*min) {reward+=7; return reward;}

        //every even num which is pow of 2
        if(diff%2==0){
            for(int i=1; i<100; i++){
            
                if((diff==pow(2,2)||diff==pow(2,3)||diff==pow(2,4)||diff==pow(2,5)) && diff<10){
                    reward *=10;    
                    return reward;
                }
            }
        }

        if(diff%4==0 && diff%8==0){
            reward += 32;
            return reward;
        }
    }

    return reward;
}

int main(){
    limits step ;

    printf("Enter min and max =\n");
    scanf("%d",&step.min);
    scanf("%d",&step.max);

    int reward = calculateTotalRewards(step.min, step.max);

    printf("The Total reward user get is %d\n",reward);

    return 0;
}