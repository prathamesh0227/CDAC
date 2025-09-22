#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    int i=0;
    int j = str.length()-1;
    while (i < j){
        char temp;
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    cout <<"Rev String is:" << str;
    }
//      {
//         /* code */
//      }
     
//     getline(cin, str); // Reads the entire line including spaces
//     string reversed = "";
//     // Reverse the string by looping from the end to the beginning
//     for (int i = str.length() - 1; i >= 0; --i)
//     {
//         reversed += str[i];
//     }
//     cout << "Reversed string is: " << reversed << endl;
//     return 0;
// }
