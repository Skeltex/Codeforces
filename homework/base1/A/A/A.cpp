#include <iostream>
#include <vector>
using namespace std;


int main()
{
    short t;
    unsigned short n;
    int delta;
    bool b_has_only_zeros, result;
    
    cin >> t;
    bool* result_arr = new bool[t];

    for (short i = 0; i < t; ++i)
    {
        cin >> n;

        vector<int> a(n);
        vector<int> b(n);

        for (short j = 0; j < n; ++j)
            cin >> a[j];

        for (short j = 0; j < n; ++j)
            cin >> b[j];


        b_has_only_zeros = true;
        // Ищем любую разность a[j] - b[j], где b[j] != 0, заодно проверяем, что b не состоит полностью из 0 
        for (short j = 0; j < n; ++j)
        {
            if (b[j])
            {
                delta = a[j] - b[j];
                b_has_only_zeros = false;
                break;
            }
        }


        if (b_has_only_zeros) // Если b состоит только из нулей, то его гарантированно можно получить
        {
            result_arr[i] = true;
            continue;
        }


        if (delta < 0) // Если b[i] > a[i], то его гарантированно нельзя получить
        {
            result_arr[i] = false;
            continue;
        }



        // Проверяем, что при условии (b[j] != 0) будет выполняться (a[j] - b[j] == delta),
        // а при (b[j] == 0) будет (a[j] - b[j] <= delta)
        
        result = true;
        for (short j = 0; j < n; ++j)
        {
            if (b[j])
            {
                if (a[j] - b[j] != delta)
                {
                    result = false;
                    break;
                }
            }
            else
            {
                if (a[j] - b[j] > delta)
                {
                    result = false;
                    break;
                }
            }
        }

        result_arr[i] = result;

    }   

    for (short i = 0; i < t; ++i)
        cout << ((result_arr[i]) ? "YES" : "NO") << endl;

    return 0;
}
