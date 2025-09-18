#include <iostream>
using namespace std;

class Demo
{
private:
    int a, b, c;

public:
    int d, e;
    void setData(int a1, int a2, int a3);
    void getData()
    {
        cout << "The Value of a is:" << a << endl;
        cout << "The Value of b is:" << b << endl;
        cout << "The Value of c is:" << c << endl;
        cout << "The Value of d is:" << d << endl;
        cout << "The Value of e is:" << e << endl;
    }
};
void Demo ::setData(int a1, int a2, int a3)
{
    a = a1;
    b = a2;
    c = a3;
}
int main()
{
    Demo test;
    test.d = 27;
    test.e = 64;
    test.setData(1, 2, 3);
    test.getData();
    return 0;
}