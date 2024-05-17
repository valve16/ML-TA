//5.1.Размещение(4)
//В массив A1, A2, …, AN(1 ≤ N ≤ 105) помещены числа 2, 3, ..., N + 1 так, что каждое значение Ai делится на i.Сколько способов такого размещения ?
//Ввод из файла INPUT.TXT.В единственной строке вводится значение N.
//Вывод в файл OUTPUT.TXT.В единственной строке выводится количество вариантов размещения.
//Примеры
//Ввод 1    Ввод 2    Ввод 3
//6          3          11
//Вывод 1   Вывод 2   Вывод 3
//1          2          8
// Глушков Олег ПС-21
#include <iostream>
#include <fstream>
#include <set>
#include <unordered_map>
#include <vector>

void TraversePlace(int N, std::set<int>& mySet, int lvl, int& res)
{
    for (int i = 2; i <= N + 1; i++)
    {
        if ((i % lvl == 0) && mySet.find(i) == mySet.end())
        {
            if (lvl == N)
            {
                res = res + 1;
            }
            else
            {
                int newLvl = lvl + 1;
                mySet.insert(i);
                TraversePlace(N, mySet, newLvl, res);
            }
            mySet.erase(i);
        }
    }
}



int main() {

    int N, res = 0;
    std::cin >> N;


    std::set<int> mySet;
    int lvl = 1;
    //TraversePlace(N, mySet, lvl, res);
  

    std::vector<int> dp(N + 2, 0);

        dp[2] = 1;

        for (int i = 3; i <= N + 1; ++i) {
            for (int j = 2; j < i; ++j) {
                if (i % j == 0) {
                    dp[i] += dp[j];
                }
            }
            dp[i]++; // Учитываем само число i
        }



    std::cout << dp[N + 1] << std::endl;
    std::cout << res << std::endl;

    return 0;
}