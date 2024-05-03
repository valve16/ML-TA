//17.1.Инверсии(4)
//Задана некоторая перестановка X = (X1, X2, …, XN) чисел от 1 до N.Требуется найти вектор инверсий и общее количество инверсий в этой перестановке, то есть количество пар чисел(i, j) таких, что i < j, а  Xi  > Xj.
//Ввод из файла INPUT.TXT.В первой строке задано число N(1 ≤  N ≤ 500000).Во второй строке заданы через пробел элементы перестановки X1, X2, …, XN.
//Вывод в файл OUTPUT.TXT.В первой строке выводится количество инверсий.Во второй строке – элементы вектора инверсий.
//Пример
//Ввод
//5
//2 5 4 1 3
//Вывод
//6
//0 0 1 3 2
// Глушков Олег ПС-21





#include <iostream>
#include <vector>
#include <fstream>

void countInversions(const std::vector<int>& permutation, std::vector<int>& inversions, int n) 
{
    //int n = permutation.size();
    for (int i = n - 1 ; i >= 0; --i) 
    {
        for (int j = i - 1; j >= 0; --j) 
        {
            if (permutation[j] > permutation[i]) 
            {
                //std::cout << permutation[i] << ">" << permutation[j] << std::endl;
                inversions[i]++;
            }
        }
    }
}

int main() {
    std::ifstream input("input.txt");

    int N;
    input >> N;

    std::vector<int> permutation(N);
    for (int i = 0; i < N; ++i) 
    {
        input >> permutation[i];
    }

    std::vector<int> inversions(N, 0);
    countInversions(permutation, inversions, N);

    int totalInversions = 0;
    for (int i = 0; i < N; ++i) 
    {
        totalInversions += inversions[i];
    }

    std::ofstream output("outout.txt");

    std::cout << totalInversions << std::endl;
    for (int inv : inversions)
    {
        std::cout << inv << " ";
    }

    return 0;
}
