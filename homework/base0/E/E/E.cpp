#include <iostream>
using namespace std;


int main()
{
    short x, y;
    cin >> x >> y;

    short interval1 = abs(x - y);
    short interval2 = 7 - interval1;


    if (interval1 < interval2)
        cout << interval1 << " " << interval2;
    else
        cout << interval2 << " " << interval1;

    return 0;
}