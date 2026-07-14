#include<iostream>
#include<fstream>

int main(){

    std::ofstream file("data.txt", std::ios::app); //app= appends

    if(!file.is_open()){
        std::cout<< "Can not opening file\n";
        return 1;
    }

    file << "Welcome in the world\n";
    file << "Welcome in the new brave world\n";
    file << "Welcome in the new far from home world\n";

    file.close();

    return 0;
}