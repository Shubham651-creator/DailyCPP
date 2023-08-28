#include<iostream>
#include"Sensor.h"
#include"SensorType.h"
#include"Functionalities.h"

// store the shared ptr in container of list
using container = std::list<std::shared_ptr<Sensor>>;

int main(){

    container listOfObjects;

    CreateObjects(listOfObjects);

    //display the objects
    for(std::shared_ptr<Sensor> value : listOfObjects){
        std::cout<<*value<<"\n\n";
    }
    std::cout<<"\n==============================================\n";
    std::cout<<"Check whether all instance of sensor reading is above 25 or not \n"
    <<ReadingAbove25(listOfObjects)<<"\n==============================================\n";

    std::cout<<"The count of sensor type TYPE_PRESSURE is "
    <<CountOfSensorOfType(listOfObjects, SensorType::TEMPERATURE)
    <<"\n==================================================\n";

    std::cout<<"display sensor instance whose reading is 15 or above and type is TYPE_PRESSURE\n";
    for(std::shared_ptr<Sensor> value : ConditionOnReadingAndType(listOfObjects)){
        std::cout<<*value<<"\n\n";
    }

    return 0;
}