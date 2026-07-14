#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::fstream file("data.txt", std::ios::in | std::ios::out);

    if (!file)
    {
        std::cout << "Open failed\n";
        return 1;
    }

    std::string line;

    file.seekp(0); //put - write

    file << "Hi ";

    file.seekg(0); //get - read

    while(std::getline(file, line)){
            std::cout<< line << std::endl;
    }

    std::cout<< file.tellg();

    file.close();
}