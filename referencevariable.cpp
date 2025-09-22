#include <iostream>
using namespace std;
int main()
{
    float x=6400;
    cout<<"Value of X is: "<<x<<endl;
    float &y=x;
    cout<<"Value of y is: "<<y<<endl;
    cout<<"Address of y is: "<<&y<<endl;
    cout<<"Address of x is: "<<&x;


} 
