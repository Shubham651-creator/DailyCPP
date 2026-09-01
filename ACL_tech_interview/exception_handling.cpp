#include<iostream>
#include<string>
#include<fstream>

class fileClass{

    private:
        std::string fileName;

    public:
        explicit fileClass(const std::string&  fileName){
            this->fileName = fileName;
        }

        ~fileClass() = default;

        void Open(){
            std::ofstream ofile(fileName);

            ofile << "How are you!!";

            if(!ofile.is_open()){
                ofile.close();
                throw std::runtime_error("Unable to open the file ");
            }
            std::cout<<"file open succesfully!!\n";
            ofile.close();
        }
};

int main(){

    fileClass file("data.txt");

    fileClass * ptrFile = new fileClass("data.txt");

    try{
        file.Open();
        std::cout<<"Application started.\n";
    }
    catch(...){
        std::cout <<"Error: " <<   std::endl;
    }
}