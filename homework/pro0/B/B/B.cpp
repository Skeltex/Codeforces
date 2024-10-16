#include <iostream>
#include <vector>
using namespace std;


vector <short> parents;
vector <short> colors;
vector<vector <short>> tree;

vector <short> result;


int dfs(short v, short t1)
{
    // Считаем сумму по цветам
    short sum = colors[v - 1];
    for (short i = 0; i < tree[v - 1].size(); ++i)
        sum += dfs(tree[v - 1][i], t1);

    if (sum == 0) // Если баланс по цветам
        result[t1] += 1;
    
    return sum;
}


int main()
{
    short t, n;
    string str_colors;

    cin >> t;
    result.resize(t);

    for (short t1 = 0; t1 < t; ++t1)
    {
        cin >> n;
        parents.clear();
        parents.resize(n - 1);
        colors.clear();
        colors.resize(n);
        tree.clear();
        tree.resize(n);

        // Ввод данных
        for (short i = 0; i < n - 1; ++i)
            cin >> parents[i];

        cin >> str_colors;
        for (short i = 0; i < n; ++i)
            colors[i] = ((str_colors[i] == 'W') ? -1 : 1);


        

        // Создание массива смежности (без предков)
        for (short i = 0; i < n - 1; ++i)
        {
            // для parents[i] потомок i + 2
            tree[parents[i] - 1].push_back(i + 2);
        }



        /*
        // Вывод массива смежности
        cout << endl;
        for (short i = 0; i < n; ++i)
        {
            cout << i + 1 << ": ";
            for (short j = 0; j < tree[i].size(); j++)
            {
                cout << tree[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        */

        

        dfs(1, t1);
    }

    for (short t1 = 0; t1 < t; ++t1)
        cout << result[t1] << endl;

    return 0;
}
