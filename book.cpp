#include <iostream>
#include <string>

using namespace std;

class book
{
public:
    string title;
    string author;
    int year;

    // Constructor
    book(string t, string a, int y)
    {
        title = t;
        author = a;
        year = y;
    }

    // Function to display data
    void displayData()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
    }
};

int main()
{
    string title, author;
    int year;

    // Input for Book 1
    cout << "Enter Book 1 Details.\n";
    cout << "Title:\n";
    cin.ignore(); // clear buffer
    getline(cin, title);
    cout << "Author:\n";
    getline(cin, author);
    cout << "Year:\n";
    cin >> year;
    book obj1(title, author, year);

    cin.ignore(); // clear buffer before reading next input

    // Input for Book 2
    cout << "\nEnter Book 2 Details.\n";
    cout << "Title:\n";
    getline(cin, title);
    cout << "Author:\n";
    getline(cin, author);
    cout << "Year:\n";
    cin >> year;
    book obj2(title, author, year);

    // Display details
    cout << "\nDetails of Book 1:\n";
    obj1.displayData();
cout<<"===================================\n";
    cout << "\nDetails of Book 2:\n";
    obj2.displayData();

    return 0;
}
