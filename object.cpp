#include <iostream>
using namespace std;

class Myinfo
{
public:
    int prn;
    string name;

    void getData()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter PRN: ";
        cin >> prn;
    }

    void displayData()
    {
        cout << "Name: " << name << endl;
        cout << "PRN: " << prn << endl;
    }
};
int main()
{
    Myinfo myDetails;
    myDetails.getData();
    myDetails.displayData();

    return 0;
}