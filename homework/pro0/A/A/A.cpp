#include <iostream>
#include <vector>
using namespace std;


vector<vector <int>> g;
vector<bool> used;


void dfs(int v)
{
    used[v - 1] = true;
    // Запускаем dfs от всех вершин, связанных с этой, в которых мы не были
    for (int i = 0; i < g[v - 1].size(); ++i)
        if (!used[g[v - 1][i] - 1])
            dfs(g[v - 1][i]);
}


int main()
{
    // Ввод графа
    int n, m, v, u;
    cin >> n >> m;
    g.resize(n);
    used.resize(n);
    
    for (int i = 0; i < m; ++i)
    {
        cin >> v >> u;
        g[v - 1].push_back(u);
        g[u - 1].push_back(v);
    }
    

    /*
    // Вывод списка смежности
    cout << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << i + 1 << ": ";
        for (int j = 0; j < g[i].size(); ++j)
            cout << g[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    */


    if (n - m != 1)
        cout << "NO";
    else
    {
        // Проверка на связность - что из вершины с номером 1 можно дойти до всех
        dfs(1);
        

        /*
        // Вывод списка посещённости
        cout << endl;
        for (int i = 0; i < n; ++i)
        {
            cout << i + 1 << ": " << used[i] << endl;
        }
        cout << endl;
        */


        
        // Если хотя бы 1 вершина осталась непосещённой - несвязный - не дерево
        bool flag = true;
        for (int i = 0; i < n; ++i)
        {
            if (!used[i])
            {
                flag = false;
                break;
            }
        }
        cout << (flag? "YES" : "NO");
    }


    return 0;
}
