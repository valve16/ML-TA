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


void Update(std::vector<int>& tree, int index, int delta) {
    while (index < tree.size()) {
        tree[index] += delta;
        index += index & -index;
    }
}

int Query(const std::vector<int>& tree, int index) { // Считаем количество элементов, меньших, чем текущий элемент
    int sum = 0;
    while (index > 0) {
        sum += tree[index];
        index -= index & -index;
    }
    return sum;
}

void СountInversions(const std::vector<int>& permutation, std::vector<int>& inversions) {
    int n = permutation.size();
    std::vector<int> tree(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        inversions[i] = Query(tree, n) - Query(tree, permutation[i]); 
        Update(tree, permutation[i], 1);
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

    СountInversions(permutation, inversions);

    int totalInversions = 0;
    for (int i = 0; i < N; ++i) 
    {
        totalInversions += inversions[i];
    }

    std::ofstream output("output.txt");

	output << totalInversions << std::endl;
    for (int inv : inversions)
    {
        output << inv << " ";
    }

    return 0;
}
