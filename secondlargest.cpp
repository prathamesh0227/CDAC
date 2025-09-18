#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter Number of Elements: ";
    cin >> n;

    if (n < 2)
    {
        cout << "Error: Enter minimum 2 numbers." << endl;
        return 1;
    }

    int elements[n];  // Note: For larger n, using vector<int> is better.
    cout << "Enter " << n << " Number of Elements: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> elements[i];
    }

    int largest, secondLargest;
    if (elements[0] > elements[1]) {
        largest = elements[0];
        secondLargest = elements[1];
    }
    else {
        largest = elements[1];
        secondLargest = elements[0];
    }

    for (int i = 2; i < n; i++)
    {
        if (elements[i] > largest)
        {
            secondLargest = largest;
            largest = elements[i];
        }
        else if (elements[i] > secondLargest && elements[i] != largest)
        {
            secondLargest = elements[i];
        }
    }

    if (largest == secondLargest)
    {
        cout << "All elements are equal." << endl;
    }
    else
    {
        cout << "The Second Largest number is: " << secondLargest << endl;
    }

    return 0;
}

// #include <iostream>
// #include <string>
// using namespace std;

// int main()
// {
//     int n;
//     cout << "Enter Number of Elements: ";
//     cin >> n;

//     if (n < 2)
//     {
//         cout << "Error: Enter minimum 2 numbers." << endl;
//         return 1;
//     }
//     int elements[n];
//     cout <<"Enter" << n << "Number of Elements: \n";
//     for (int i = 0; i < n; i++)
//     {
//         cin >> elements[i];
//     }
//     int largest, secondLargest;
//     if (elements[0] > elements[1]){
//         largest = elements[0];
//         secondLargest = elements[1];
//     }
//     else
//     {
//         largest=elements[1];
//         secondLargest=elements[0];
//     }
    
//     for (int i = 2; i < n; i++)
//     {
//         if (elements[i] > largest)
//         {
//             largest = elements[i]
//             {
//                 secondLargest = largest;
//                 largest = elements[i];
//             }
//             else if (elements[i] > secondLargest && elements[i] != largest)
//             {
//                 secondLargest = elements[i];
//             }
//             if (largest = secondLargest)
//             {
//                 cout << "All Elements are equal" << endl;
//             }
//             else
//             {
//                 cout << "The Second Largest number is: " << secondLargest << endl;
//             }
//         }
//         return 0;
//     }
// }