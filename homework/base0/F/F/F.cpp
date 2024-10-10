#include <iostream>
using namespace std;


int main()
{
    short n;
    cin >> n;

    short* h = new short[n];
    for (short i = 0; i < n; ++i)
        cin >> h[i];
        
    int p = 2 * n + h[0] + h[n - 1];
    
    for (short i = 0; i < n - 1; ++i)
        p += abs(h[i + 1] - h[i]);

    cout << p;


    return 0;
}
