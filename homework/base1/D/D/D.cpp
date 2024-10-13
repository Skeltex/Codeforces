#include <iostream>
#include <vector>
using namespace std;


inline bool is_sorted(int n, vector<int> a)
{
    for (int i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1])
            return false;
    return true;
}


int main()
{
    short t;
    int n, left_index, right_index;
    cin >> t;

    vector<int> a;
    vector<string> result(t);


    for (short t1 = 0; t1 < t; ++t1)
    {
        // Ввод вектора
        cin >> n;
        a.resize(n);

        for (int i = 0; i < n; ++i)
            cin >> a[i];


        // Меняем знаки слева на минусы, справа на плюсы
        left_index = 0;
        right_index = n - 1;
        while (true)
        {
            while ((a[left_index] < 0) && (left_index < n - 1))
            {
                ++left_index;
                if (left_index >= right_index)
                    break;
            }
             

            while ((a[right_index] > 0) && (right_index > 0))
            {
                --right_index;
                if (left_index >= right_index)
                    break;
            }
            
            if (left_index >= right_index)
                break;


            a[left_index] *= -1;
            a[right_index] *= -1;

        }

        result[t1] = (is_sorted(n, a)? "YES" : "NO");
    }


    // Вывод ответа
    for (short t1 = 0; t1 < t; ++t1)
        cout << result[t1] << endl;


    return 0;
}
