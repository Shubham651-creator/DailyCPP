#include<iostream>
#include<string>

int main(){

    std::string name = "Shubham";

    std::string revName(name.size(), ' ');

    for(int i= name.size()-1; i >=0 ; i--){
        // revName += name[i];

        revName[name.size()-i-1] = name[i];
    }

    std::cout<< revName;
}