#include<iostream>
#include<vector>
#include<chrono>

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

class Point
{
public:
	Point(const int& x, const int& y) :x(x), y(y) {}
	const int x;
	const int y;
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

vector<Point> points;

void DFS(size_t index)//[x][y]
{
	const int& x = points[index].x;
	const int& y = points[index].y;

	for (int i = matrix[x][y] + 1; i < 10; i++)//���������Լ��Ź���
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

		//�пɷ��õ�����

		if (!flags) {
			matrix[x][y] = i;
			if (++index == points.size())//�Ƿ����
			{
				return;
			}
			DFS(index);//������һ���ո�
			return;
		}

	}

	//û�пɷ��õ�����
	matrix[x][y] = 0;
	DFS(--index);

	return;
}

int main()
{
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
				points.push_back(Point(i, j));
			}
		}
	}

	DFS(0);

	timeEnd = timer.now();

	printMatrix();

	cout << "Time " << chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart).count() << "ms\n";

	cin.get();
	return 0;
}