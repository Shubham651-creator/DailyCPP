#include<iostream> 
#include<exception>
using namespace std;

int main(){

    try{
        int arr[5];
        
        // throw 100;
        throw runtime_error("out of range;");

    } 
    catch( int num){
        cout<< "the int number :" << num;
    }
    catch(runtime_error& e){
        cout<< e.what();
    }

    return 0;
}