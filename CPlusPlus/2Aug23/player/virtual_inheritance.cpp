// Virtual mode of inheritance
// Diamond inheritance

#include<iostream>

class Player{

};

class Cricketer: public Player{

    public:
    void show(){
        std::cout<<"\nhello, i am cricketer\n";
    }

};

// This Virtual keyword gives the common data only once to his derived class(AllRounder)

class Batsman : virtual public Cricketer{

    protected:
    int bat1 = 9, bat2 = 10;
    
    public:
    void show(){
        std::cout<<"\n i am in Batsman\n";
    }

};

class Bowler : virtual public Cricketer{

    public:
    void show(){
        Cricketer::show();
        std::cout<<"\n i am in Bowler\n";
    }

};

class AllRounder: public Batsman, public Bowler{

    public:
    void show(){
        std::cout<<"\n i am in all rounder\n";
        Bowler::show();
        //Batsman::show(); //create ambiguty, so use protect data members
        std::cout<<"batsman::"<<bat1<<bat2<<"\n";
    }
};

int main(){

    AllRounder a;
    a.show();

    // a.Batsman::show();
    // a.Bowler::show();
    return 0;
}