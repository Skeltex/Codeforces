#include <iostream>
using namespace std;


int main()
{
    short n, m, max_spacing, distance;
    int count_of_ways = 0;
    cin >> n >> m;

    if (m == 1)
    {
        count_of_ways = n;
    }
    else
    {
        max_spacing = (n - m) / (m - 1);
        for (short spacing = 0; spacing <= max_spacing; ++spacing)
        {
            distance = m + spacing * (m - 1);
            count_of_ways += n - distance + 1;
        }
    }

    cout << count_of_ways;


    return 0;
}
