
#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include "5.1.h"



//int countWays(const int& N) {
//    long long dp[N + 2] = { 0 };
//    dp[1] = 1;
//    for (int i = 2; i <= N + 1; i++) {
//        dp[i] = (dp[i - 1] * i) % MOD;
//    }
//    return dp[N + 1];
//}

void TraversePlace(int N, std::set<int>& mySet, int lvl, int& res)
{
    for (int i = 2; i <= N + 1; i++)
    {
        if (mySet.find(i) == mySet.end() && (i % lvl == 0))
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
  
    //std::vector<long long> dp(N + 1, 0);
    //for (int i = 2; i <= N + 1; ++i) {
    //    for (int j = 1; j <= N; j++) {
    //        if (i % j == 0)
    //        {
    //            dp[j] += dp[j - i];
    //        }
    //    }
    //}

    std::vector<int> dp(N + 2, 0);
    dp[0] = 1;

    for (int i = 2; i <= N + 1; ++i) {
        std::cout << i << std::endl;
        for (int j = i; j <= N + 1; j += i) {
            dp[j] += dp[j - i];
            int k = 0;
            for (int res : dp)
            {
                std::cout << k << " dp: " << res << std::endl;
                k++;
            }
            //std::cout << j << " " << dp[j] << std::endl;
            
        }
    }

    //std::cout << dp[N + 1] << std::endl;

    // Вывод количества способов размещения
   // std::cout << res << std::endl;

   /* vector<int> arr(N, 0);
    //for (int i = 1; i <= N; i++)
    {

    }*/



    return 0;
}