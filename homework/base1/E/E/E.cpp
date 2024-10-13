#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    short n, count_remove = 0;
    cin >> n;
    vector<int> a(n);

    // Вводим вектор
    int sum = 0;
    for (short i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
        

    sort(a.begin(), a.end());
    
    for (short i = n - 1; i >= 0; --i) // Начинаем с конца - самых больших сторон
    {
        if (a[i] >= (sum - a[i])) // Если одна сторона больше суммы всех остальных - удаляем
        {
            if ((n - count_remove) <= 2)
                break;
            ++count_remove;
            sum -= a[i]; // В явном виде удалять из вектора долго, поэтому просто не учитываем эту сторону в сумме
        }
    }
    
    // После всех удалений должно остаться хотя бы 3 стороны
    cout << (((n - count_remove) >= 3) ? count_remove : -1);


    return 0;
}
