#include<iostream>
#include<functional>
#include"Sensor.h"
#include"SensorType.h"
#include"Functionalities.h"

using refPointer = std::reference_wrapper< std::shared_ptr<Sensor> >;
// store the shared ptr in container of list
using container = std::list<refPointer>;

int main(){

    container listOfObjects;

    CreateObjects(listOfObjects);

    //display the objects
    for(refPointer& value : listOfObjects){
        std::cout<< *value.get() <<"\n\n";
    }
    std::cout<<"\n==============================================\n";
    std::cout<<"Check whether all instance of sensor reading is above 25 or not \n"
    <<ReadingAbove25(listOfObjects)<<"\n==============================================\n";

    std::cout<<"The count of sensor type TYPE_PRESSURE is "
    <<CountOfSensorOfType(listOfObjects, SensorType::TEMPERATURE)
    <<"\n==================================================\n";

    std::cout<<"display sensor instance whose reading is 15 or above and type is TYPE_PRESSURE\n";
    for(refPointer& value : ConditionOnReadingAndType(listOfObjects)){
        std::cout<<*value.get()<<"\n\n";
    }

    return 0;
}