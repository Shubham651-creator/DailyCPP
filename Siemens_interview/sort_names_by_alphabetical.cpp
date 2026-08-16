#include <iostream>
#include <string>
#include <vector>

int main(){

    std::vector<std::string> input
    {"shubham", "awale", "zanjale", "beta"};

    for(int i=0; i< input.size(); i++){
        for(int j=i+1; j<input.size(); j++){
            if(input[i]  > input[j] ){
                std::string temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
        }
    }

    for(auto& i : input){
        std::cout<< i << std::endl;
    }

}