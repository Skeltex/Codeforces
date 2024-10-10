#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    short p, k;
    cin >> p >> k;

    int s = pow(p / ((k + 1) * 2), 2) * k;
    cout << s;

    return 0;
}
