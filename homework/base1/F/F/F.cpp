#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    short t, n, m, temp, sum;
    cin >> t;
    
    vector<short> result(t);

    for (short t1 = 0; t1 < t; ++t1)
    {
        cin >> n >> m;

        sum = 0;
        for (short i = 0; i < n; ++i)
        {
            cin >> temp;
            sum += temp;
        }

        result[t1] = ((m < sum) ? sum - m : 0);
    }

    for (short t1 = 0; t1 < t; ++t1)
        cout << result[t1] << endl;


    return 0;
}
