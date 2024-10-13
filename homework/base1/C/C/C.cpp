#include <iostream>
#include <vector>
using namespace std;


int main()
{
    short t, n, count;
    bool flag;
    cin >> t;

    vector<int> a;
    vector<int> result(t);


    for (short t1 = 0; t1 < t; ++t1)
    {
        // Ввод вектора
        cin >> n;
        a.resize(n);

        for (short i = 0; i < n; ++i)
            cin >> a[i];


        // Делаем возрастающим начиная с правого конца
        count = 0;
        flag = false;
        for (short i = n - 2; i >= 0; --i)
        {
            while (a[i] >= a[i + 1])
            {
                if (a[i] <= 1) // Если уже некуда уменьшать 
                {
                    if (a[i] >= a[i + 1])
                    {
                        flag = true;
                        break;
                    }
                }
                a[i] /= 2;
                ++count;
            }
            if (flag)
                break;
        }

        result[t1] = ((flag) ? -1 : count);
    }


    // Вывод ответа
    for (short t1 = 0; t1 < t; ++t1)
        cout << result[t1] << endl;


    return 0;
}
