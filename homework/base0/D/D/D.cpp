#include <iostream>
using namespace std;


int main()
{
    short x;
    cin >> x;

    if (x <= 28)
        cout << 2;
    else if (x <= 52)
        cout << 3;
    else if (x <= 77)
        cout << 4;
    else
        cout << 5;

    return 0;
}
