#include <iostream>
#include <vector>
using namespace std;


int main()
{
    short t;
    int n, max1, max2;
    cin >> t;

    vector<int> s;
    vector<vector<int>> result(t);


    for (short t1 = 0; t1 < t; ++t1)
    {
        // Ввод вектора
        cin >> n;
        s.resize(n);

        for (int i = 0; i < n; ++i)
            cin >> s[i];


        // Определяем 2 наибольших элемента
        max1 = 0;
        max2 = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] > max1)
            {
                if (max1 > max2)
                    max2 = max1;
                max1 = s[i];
                continue;
            }

            if (s[i] > max2)
                max2 = s[i];
        }


        // Запись в вектор ответов
        result[t1].resize(n);

        for (int i = 0; i < n; ++i)
            result[t1][i] = ((s[i] == max1) ? (s[i] - max2) : (s[i] - max1));
    }


    // Вывод ответа
    for (short t1 = 0; t1 < t; ++t1)
    {
        n = result[t1].end() - result[t1].begin();
        for (int i = 0; i < n; ++i)
        {
            cout << result[t1][i] << " ";
        }
        cout << endl;
    }


    return 0;
}
