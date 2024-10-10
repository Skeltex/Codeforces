#include <iostream>
using namespace std;


int main()
{
    short w;
    cin >> w;

    cout << (((w >= 4) && !(w % 2)) ? "YES" : "NO");
    

    return 0;
}
