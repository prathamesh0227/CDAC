#include <iostream>
using namespace std;

int main() {
    int a[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int transpose[3][3];

    // Compute transpose
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            transpose[j][i] = a[i][j];
        }
    }

    // Display transpose
    cout << "Transpose of the matrix:\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
