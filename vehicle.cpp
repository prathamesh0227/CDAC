#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Vehicle
{
protected:
    int vehicleNo;
    string vehicleName;
    float rentalRate;
    bool available;

public:
    Vehicle(int id, const string &br, float rate)
        : vehicleNo(id), vehicleName(br), rentalRate(rate), available(true) {}

    virtual ~Vehicle() {}

    virtual void display() const
    {
        cout << "Vehicle Registration Number:" << vehicleNo << endl;
        cout << "Make and Model:" << vehicleName << endl;
        cout << "Rent Per Day: RS" << rentalRate << endl;
        cout << "Availability:" << available << endl;
    }
    virtual float calculateRentalCost(int days) const
    {
        return rentalRate * days;
    }
    bool getAvailability() const
    {
        return available;
    }
    int getID() const{
        return vehicleNo;
    }
    void rentVehicle()
    {
        if (available)
        {
            available = false;
            cout << "Vehicle rented successfully" << endl;
        }
        else
        {
            cout << "Vehicle not available" << endl;
        }
    }
    void returnVehicle()
    {
        available = true;
        cout << "Vehicle returned successfully" << endl;
    }
};

class Car : public Vehicle
{
public:
    Car(int id, const string &br, float rate)
        : Vehicle(id, br, rate) {}

    void display() const override
    {
        cout << "Car Details:" << endl;
        Vehicle::display();
    }
};

class Bike : public Vehicle
{
public:
    Bike(int id, const string &br, float rate)
        : Vehicle(id, br, rate) {}

    void display() const override
    {
        cout << "Bike Details:" << endl;
        Vehicle::display();
    }
};

int main()
{
    const int MAX_VEHICLES = 10;
    Vehicle *vehicle[MAX_VEHICLES];

    vehicle[0] = new Car(6400, "Hyundai-CRETA", 4000.0);
    vehicle[1] = new Car(2700, "Toyota-INNOVA CRYSTA", 7000.0);
    vehicle[2] = new Car(0015, "Toyota-INNOVA", 6000.0);
    vehicle[3] = new Car(9229, "Toyota-FORTUNER", 9000.0);
    vehicle[4] = new Car(6714, "Mahindra-THAR", 3500.0);
    vehicle[5] = new Car(6543, "Audi-Q5", 10000.0);
    vehicle[6] = new Car(5105, "Mercedes-E220", 15000.0);
    vehicle[7] = new Bike(2363, "RE-CLASSIC 350", 1000.0);
    vehicle[8] = new Bike(6969, "RE-GT650", 1500.0);
    vehicle[9] = new Car(9009, "Kawasaki-Z900", 3000.0);

    cout << "Vehicle Management System:\n";

    for (int i = 0; i < MAX_VEHICLES; i++)
    {
        vehicle[i]->display();
        cout << "======================\n";
    }

    int choice, days;
    cout << "Enter Vehicle Number to rent: ";
    cin >> choice;

    bool found = false;
    for (int i = 0; i < MAX_VEHICLES; i++)
    {
        if (vehicle[i]->getAvailability() && vehicle[i]->getID() == choice)
        {
            cout << "Enter number of days to rent: ";
            cin >> days;
            vehicle[i]->rentVehicle();
            cout << "Total Rent for " << days << " days is: Rs " << vehicle[i]->calculateRentalCost(days) << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Vehicle not available" << endl;
    }
    for (int i = 0; i < MAX_VEHICLES; i++)
    {
        delete vehicle[i];
    }
    return 0;
}