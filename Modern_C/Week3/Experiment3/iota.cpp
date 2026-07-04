#include<iostream>
#include<vector>
#include<numeric>

int main(){

    std::vector<int> v(10);

    std::iota(v.begin(), v.end(), -2);

    for(int & value : v){
        std::cout<<value<<"\t";
    }
}