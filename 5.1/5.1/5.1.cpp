
#include <iostream>
#include <fstream>
#include <set>
#include <unordered_map>
#include <vector>



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

void TraversePlace1(int N, std::vector<bool>& used, int lvl, int& res) {
    for (int i = 2; i <= N + 1; ++i) {
        if (!used[i]) {
            if ((i % lvl) == 0) {
                if (lvl == N) {
                    ++res;
                }
                else {
                    used[i] = true;
                    TraversePlace1(N, used, lvl + 1, res);
                    used[i] = false;
                }
            }
        }
    }
}

//int countPermutations(int N) {
//    std::vector<int> dp(N + 1, 0);
//    dp[0] = 1; // Базовый случай: один способ размещения для пустого массива
//
//    for (int i = 1; i <= N; ++i) {
//        for (int j = 1; j * j <= i + 1; ++j) {
//            if ((i + 1) % j == 0) {
//                dp[i] = dp[i] + dp[j - 1];
//                if (j != (i + 1) / j && j != 1) {
//                    dp[i] = dp[i] + dp[(i + 1) / j - 1];
//                }
//            }
//        }
//    }
//
//    return dp[N - 1];
//}


int main() {

    int N, res = 0;
    std::cin >> N;


    std::set<int> mySet;
    int lvl = 1;
    TraversePlace(N, mySet, lvl, res);
  

    std::vector<int> dp(N + 2, 0);
    std::vector<int> dp1(N + 3, 0);
    std::vector<int> ways(N + 1, 0);

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