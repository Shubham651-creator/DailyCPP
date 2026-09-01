/******************************************************************************
nums = [2,7,11,15],
target = 9
Output: [0,1]

*******************************************************************************/

#include <iostream>
#include<vector>

std::vector<int> 
findSumOfTwo(std::vector<int> input, int target){
    for(int i=0; i<input.size(); i++){
       for(int j=i+1; j<input.size(); j++){
           if(input[i]+ input[j] == target){
               return {i,j};
           }
       }
    }
    
    return {};
}

int main()
{
    std::vector<int> input = {2,7,11,15};
    
    std::vector<int> store = findSumOfTwo(input, 9);
    
    std::cout<< store[0]<< ", " << store[1];

    return 0;
}