﻿#include <iostream>
using namespace std;


int main()
{
    int a, b;
    cin >> a >> b;

    while (a != b)
    {
        if (a > b)
            a /= 2;
        else
            b /= 2;
    }

    cout << a;

    return 0;
}
