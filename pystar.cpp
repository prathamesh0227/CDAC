#include <iostream>
using namespace std;

void invertedFullPyramid(int n) {
    for (int i = 0; i < n; i++) {
        // Print leading spaces
        for (int space = 0; space < i; space++) {
            cout << "  ";
        }
        // Print stars: 2*(n - i) - 1
        for (int star = 0; star < 2 * (n - i) - 1; star++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void fullPyramid(int n) {
    for (int i = 0; i < n; i++) {
        // Print leading spaces
        for (int space = 0; space < n - i - 1; space++) {
            cout << "  ";
        }
        // Print stars: 2*i + 1
        for (int star = 0; star < 2 * i + 1; star++) {
            cout << "* ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout<<"Enter 'n':";
    cin>> n;
    cout << "Inverted Full Pyramid:\n";
    invertedFullPyramid(n);
    
    cout << "\nFull Pyramid:\n";
    fullPyramid(n);
    
    return 0;
}
