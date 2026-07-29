#include<iostream>
#include<fstream>
#include<string>

int main(){
    //write into the file
    std::ofstream file("data.txt");

    file <<"Welcome to my world!!!" <<std::endl;
    file << "Let's ready to fight."<<std::endl;

    file.close();

    // Read the rfile
    std::ifstream rfile("data.txt");

    std::string line;
    while(std::getline(rfile, line)){
        std::cout<< line << std::endl;
    }

    rfile.close();

    return 0;
}