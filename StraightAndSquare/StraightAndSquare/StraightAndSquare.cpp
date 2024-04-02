//11.2.Прямая и квадраты(5)
//В прямоугольной декартовой системе координат прямая задана двумя принадлежащими ей точками(0, W) и(100N, E) (1 ≤ N ≤ 100, 0 ≤ W, E ≤ 100N).
// Также заданы N 2 квадратов со сторонами, параллельными осям координат.Квадрат Si, j имеет координаты углов(100i, 100j) и(100i - 100, 100j - 100), 
// где i, j = 1, 2, ..., N.Требуется найти количество квадратов, имеющих общую точку с прямой.
//Ввод из файла INPUT.TXT.В первой строке находятся три целых числа, N, W и E, разделенные пробелами.
//Вывод в файл OUTPUT.TXT.Вывести одно число - количество квадратов.
//Примеры
//Ввод
//3 150 50
//Вывод
//4
//
// VS 2022
// Глушков Олег ПС 21



#include <iostream>

#include <fstream>

struct Coords {
    int x;
    int y;
};

int main() {

    std::ifstream inFile("input.txt");
    std::ofstream outFile("output.txt");
    int N, W, E;
    inFile >> N >> W >> E;
    Coords firstPoint = { 0, W };
    Coords secondPoint = { 100 * N, E };

    double k = static_cast<double>(secondPoint.y - firstPoint.y) / (secondPoint.x - firstPoint.x);

    int b = firstPoint.y - k * firstPoint.x;
    int count = 0;
    for (int i = 1; i <= N; ++i) 
    {
        for (int j = 1; j <= N; ++j) 
        {
            if (((100 * i - 100) * k + b >= 100 * j - 100) && (k * 100 * i + b <= 100 * j)) // проверка прямой проходит она между точками квадрата или нет
            {
                count++;
            }
        }
    }
    outFile << count;
    return 0;
}