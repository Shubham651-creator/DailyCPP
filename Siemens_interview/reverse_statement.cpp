#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>

int main(){

    std::string name = "My name is shubham";

    //1. By algorithm
    std::reverse(name.begin(), name.end());
    std::cout<< name << std::endl;

    //2. By stringstream - reverse word-by-word
    std::string text = "My text is shubham";
    std::istringstream ss(text);
    std::string word;
    std::vector<std::string> vec;

    while(ss >> word){
        vec.push_back(word);
        std::cout<< word << " ";
    }

    std::cout<< std::endl;
    for(int i = vec.size()-1; i>=0; i--){
        std::cout<< vec[i] << " ";
    }

    std::cout<< std::endl;
    int a = 'a';
    std::cout<< a;

}