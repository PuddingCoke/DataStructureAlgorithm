#include<iostream>
#include<chrono>

#include"PointList.hpp"

using namespace std;

int matrix[9][9] =
{
	{8,0,0,0,0,0,0,0,0},
	{0,0,3,6,0,0,0,0,0},
	{0,7,0,0,9,0,2,0,0},
	{0,5,0,0,0,7,0,0,0},
	{0,0,0,0,4,5,7,0,0},
	{0,0,0,1,0,0,0,3,0},
	{0,0,1,0,0,0,0,6,8},
	{0,0,8,5,0,0,0,1,0},
	{0,9,0,0,0,0,4,0,0}
};

void printMatrix()
{
	for (size_t i = 0; i < 9; i++)
	{
		for (size_t j = 0; j < 9; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void DFS(Point* const point)//[x][y]
{
	const int& x = point->x;
	const int& y = point->y;

	for (int i = matrix[x][y] + 1; i < 10; i++)//遍历行列以及九宫格
	{
		bool flags = false;
		for (int j = 0; j < 9; j++)
		{
			if (matrix[j][y] == i || matrix[x][j] == i || matrix[x / 3 * 3 + j / 3][y / 3 * 3 + j % 3] == i)
			{
				flags = true;
				break;
			}
		}

		//有可放置的数字

		if (!flags) 
		{
			matrix[x][y] = i;
			if (point->next)
			{
				DFS(point->next);//遍历下一个空格
			}
			return;
		}

	}

	//没有可放置的数字
	matrix[x][y] = 0;

	if (point->prev)
	{
		DFS(point->prev);
	}

	return;
}

int main()
{
	List* points = new List();

	chrono::high_resolution_clock timer;

	std::chrono::steady_clock::time_point timeStart;

	std::chrono::steady_clock::time_point timeEnd;

	printMatrix();

	timeStart = timer.now();

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (matrix[i][j] == 0)
			{
				points->addNode(i, j);
			}
		}
	}

	DFS(points->head);

	timeEnd = timer.now();

	delete points;

	printMatrix();

	cout << "Time " << chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart).count() << "ms\n";

	cin.get();

	return 0;
}