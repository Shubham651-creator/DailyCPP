#include <iostream>

// enum is stored as int constant
enum Speciality
{
    GYNAC,
    SURGICAL,
    CARDIAC
};

std::string displayEnumValue(Speciality sp)
{
    if (sp == Speciality::CARDIAC)
        return "Cardiac";
    if (sp == Speciality::SURGICAL)
        return "SURGICAL";
    if (sp == Speciality::GYNAC)
        return "GYNAC";

    return "nothing";
}

Speciality returnEnum(std::string enumName){
    if(enumName == "cardiac") return Speciality::CARDIAC;
    if(enumName == "surgical") return Speciality::SURGICAL;
    if(enumName == "gynac") return Speciality::GYNAC;

    return Speciality::GYNAC;
}

class Doctor
{
    std::string doctorId;
    std::string doctorName;
    enum Speciality sp;

public:
    Doctor()
    {
        doctorId = 1;
        doctorName = "Yadnesh";
        sp = Speciality::CARDIAC;
    }
    // member initiazer list
    Doctor(std::string id, std::string name, Speciality s) : doctorId(id), doctorName(name), sp(s)
    {
    }

    void show()
    {
        std::cout << "Doctor id = " << doctorId << "\n";
        std::cout << "Doctor Name = " << doctorName<< "\n";
        std::cout << "Speciality = " << displayEnumValue(sp) << "\n\n";
    }
};

void search(Doctor d[], int size)
{
}
int main()
{

    // Doctor *d[3]; // arrays of pointers i.e 2D array

    // d[0] = new Doctor("111", "shi", Speciality::GYNAC);
    // d[1] = new Doctor("121", "doe", Speciality::SURGICAL);
    // d[2] = new Doctor();

    // Doctor d[3];
    std::string dId, dName,enumName;
    std::cin>>dId>>dName;
    
    std::cin>> enumName;
    Speciality spec = returnEnum(enumName);

    Doctor d4(dId, dName, spec);
    d4.show();

    // search(d, 3);
    // for (int i = 0; i < 3; i++)
    // {
    //     d[i].show();
    // }

    // for (int i = 0; i < 3; i++)
    // {
    //     delete d[i];
    // }
    return 0;
}
