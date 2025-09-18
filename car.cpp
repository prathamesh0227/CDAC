// display car details
#include <iostream>
using namespace std;

class Car
{
public:
    string vehicleNo;
    string brand;
    string model;

        void getData()
    {
        cout << "Enter Vehicle Number: ";
        cin >> vehicleNo;
        cout << "Enter Brand: ";
        cin >> brand;
        cout << "Enter Model: ";
        cin >> model;
    }

    void displayData()
    {
        cout<<vehicleNo<<" "<<brand<<" "<<model<<" "<<"\n";
    }
};


    int main(){
        Car dad, son;

        cout <<"Enter Dad's car details:\n";
        dad.getData();
        cout<<"Enter Son's car details:\n";
        son.getData();

        cout<<"Dad's Car:\n";
        dad.displayData();

        cout<<"Son's Car:\n";
        son.displayData();

         return 0;


    };

    //+++===========================================================+++
    //Pre defined:
    // {
    //     Car dad;
    //     dad.serialNo = 1;
    //     dad.vehicleNo = "MH14DD0027";
    //     dad.brand = "Merecedes";
    //     dad.model = "MaybachGLS600";
    //     dad.kms = 2000;

    //     Car son;
    //     son.serialNo = 2;
    //     son.vehicleNo = "MH14PD0027";
    //     son.brand = "RangeRover";
    //     son.model = "SportSV";
    //     son.kms = 1000;

        // cout << dad.serialNo << " " << dad.vehicleNo << " " << dad.brand << " " << dad.model << " " << dad.kms << "\n";
        // cout << son.serialNo << " " << son.vehicleNo << " " << son.brand << " " << son.model << " " << son.kms << "\n";