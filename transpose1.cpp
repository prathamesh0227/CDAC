#include <iostream>
using namespace std;

int main()
{
    int a[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int transpose[3][3];

    cout << "Matrix is :\n";
    // DIsplay Matrix
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << a[i][j] << "\t ";
        }
        cout << endl;
    }

    cout <<"==================================================="<<endl;

    // compute transpose
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            transpose[j][i] = a[i][j];
        }
    }
    // Display Transpose Matrix
    cout << "Transpose of the Matrix is:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << transpose[j][i] << "\t ";
        }
        cout << endl;
    }
    return 0;
}
