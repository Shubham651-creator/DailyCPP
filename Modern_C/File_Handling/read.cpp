#include<iostream>
#include<fstream>
#include<string>

int main(){

    std::ifstream file("data.txt");

    if(!file.is_open()){
        std::cout<< "Can not opening file\n";
        return 1;
    }

    std::string s;
    while(std::getline(file,s)){
        std::cout<< s << std::endl;
    }

    file.close();
    
    return 0;
}