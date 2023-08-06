#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>

enum class flightClass{
    ECONOMY,
    PREMIUMECONOMY,
    BUSINESS,
    FIRSTCLASS
};

class Flight
{
private:
    std::string flightNumber;
    enum flightClass fClass;
    int ticketsAvailable;
    int ticketIssued;
    std::string fromPlace;
    std::string toPlace;

public:
    Flight();
    Flight(std::string flight_number, flightClass f_class, int tickets_avilable, int ticket_issued, std::string to_place);
    ~Flight();
    void display();
    void bookFlight();
    int calculateFare();
    flightClass acceptFlightClass(int );
    flightClass displayFlightClass( );

    std::string getFightNumber() const { return flightNumber; }
    void setFightNumber(const std::string &fightNumber_) { flightNumber = fightNumber_; }

    enum flightClass getFClass() const { return fClass; }
    void setFClass(const enum flightClass &fClass_) { fClass = fClass_; }

    int getTicketsAvailable() const { return ticketsAvailable; }
    void setTicketsAvailable(int ticketsAvailable_) { ticketsAvailable = ticketsAvailable_; }

    int getTicketIssued() const { return ticketIssued; }
    void setTicketIssued(int ticketIssued_) { ticketIssued = ticketIssued_; }

    std::string getFromPlace() const { return fromPlace; }
    void setFromPlace(const std::string &fromPlace_) { fromPlace = fromPlace_; }

    std::string getToPlace() const { return toPlace; }
    void setToPlace(const std::string &toPlace_) { toPlace = toPlace_; }

};

#endif // FIGHT_H
