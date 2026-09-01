#include<iostream>
#include<map>
#include<unordered_map>

int main(){
    std::map<int, float> mp;
    std::unordered_map<int, float> ump;

    mp[1] = 1.1f;
    mp[2] = 2.1f;
    mp[3] = 3.1f;

    for(auto[first, second] : mp){
        std::cout<< first << " : " << second << std::endl;
    }

    if(mp.find(2) != mp.end()){
        std::cout<< "found: "<< mp.find(2)->second;
    }
}