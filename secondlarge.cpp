#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter Number of Elements :";
    cin >> n;

    if (n < 2)
    {
        cout << "Error: Minimum 2 numbers required.\n";
        return 1;
    }
    int element[n];
    cout << "Enter " << n << " Elements: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> element[i];
    }
    int largest, secondLargest;
    if (element[0] > element[1])
    {
        element[0] = largest;
        element[1] = secondLargest;
    }
    else
    {
        largest = element[1];
        secondLargest = element[0];
    }
    for (int i = 2; i < n; i++)
    {
        if (element[i] > largest)
        {
            secondLargest = largest;
            largest = element[i];
        }
        else if (element[i] > secondLargest && element[i] != largest)
        {
            secondLargest = element[i];
        }
    }
    if (secondLargest == largest)
    {
        cout << "All Numbers are Equal." << endl;
    }
    else
    {
        cout << "Second Largest number is: " << secondLargest << endl;
    }
    return 0;
}