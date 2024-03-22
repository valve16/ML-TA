//2.7. Квадратный дом (5)
//В квадратной комнате размером M × M дециметров расставлена квадратная мебель.
//Стороны каждого предмета мебели параллельны стенам комнаты.
//Размер каждого предмета мебели представляется целым числом дециметров, а сам предмет отстоит от стен на целое число дециметров.
//Так как мебель может быть разной по высоте, то одну и ту же площадь пола могут занимать несколько предметов
//(например, табуретки могут быть полностью или частично задвинуты под стол).
//Сверху комната освещена точечным источником света, расположенным очень высоко, поэтому лучи падают строго перпендикулярно полу.
//Имеются N предметов мебели, для каждого из которых заданы в дециметрах размер D, а также расстояния от левой стены X и от передней стены Y.
//Требуется написать программу, которая определяет площадь максимальной освещенной области на полу.
//Областью считается совокупность квадратных дециметров пола, на которые не падает тень от мебели и такой,
//что любой квадратный дециметр области граничит хотя бы одной своей стороной с другим квадратным дециметром этой же области
//(исключение составляет только область из одного квадратного дециметра).
//Глушков Олег ПС-21

#include <iostream>
#include <fstream>
#include <vector>


void CheckNextSquare(int x, int y, int& count, std::vector<std::vector<bool>>& vecOfVec, int& sizeHome)
{
	if ((x < sizeHome) && (x >= 0) && (y < sizeHome) && (y >= 0))
	{
		if (!vecOfVec[y][x]) {
			count++;
			vecOfVec[y][x] = true;
			CheckNextSquare(x + 1, y, count, vecOfVec, sizeHome);
			CheckNextSquare(x, y - 1, count, vecOfVec, sizeHome);
			CheckNextSquare(x - 1, y, count, vecOfVec, sizeHome);
			CheckNextSquare(x, y + 1, count, vecOfVec, sizeHome);
		}
	};
};

int main()
{
	std::ifstream inFile("input3.txt");
	std::ofstream outFile("output.txt");
	int countThings, sizeHome = 0;
	inFile >> countThings >> sizeHome;
	std::vector<std::vector<bool>> homeVector(sizeHome, std::vector<bool>(sizeHome, 0));

	for (int i = 0; i < countThings; i++)
	{
		int sizeThing, posX, posY;
		inFile >> sizeThing >> posX >> posY;
		for (int x = posX; x < (posX + sizeThing); x++)
		{
			for (int y = posY; y < (posY + sizeThing); y++)
			{
				homeVector[y][x] = 1;
			}
		}
	}
	std::vector<int> countLightList;
	int countLights = 0;
	for (int x = 0; x < sizeHome; x++) {
		for (int y = 0; y < sizeHome; y++)
		{
			countLights = 0;
			if (!homeVector[y][x]) {
				countLights++;
				homeVector[y][x] = true;
				CheckNextSquare(x + 1, y, countLights, homeVector, sizeHome);
				CheckNextSquare(x, y - 1, countLights, homeVector, sizeHome);
				CheckNextSquare(x - 1, y, countLights, homeVector, sizeHome);
				CheckNextSquare(x, y + 1, countLights, homeVector, sizeHome);
				countLightList.push_back(countLights);
			};
		}
	}
	countLightList.push_back(countLights);
	outFile << *max_element(countLightList.begin(), countLightList.end());
}
