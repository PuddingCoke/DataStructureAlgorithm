#include<iostream>

using std::cout;
using std::cin;

int* indices = nullptr;

const int n = 8;

void printBoard()
{
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (indices[y] == x)
			{
				cout << 1;
			}
			else
			{
				cout << 0;
			}
			cout << " ";
		}
		cout << "\n";
	}
}

bool set(const int& y, const int& x)
{

	for (int i = 0; i < n; i++)
		if (indices[i] == x)
			return false;

	for (int i = (y - x > -1) ? 0 : (x - y); i < x + 1; i++)
		if (indices[i + y - x] == i)
			return false;

	for (int i = x; i < ((x + y < n) ? (x + y + 1) : n); i++)
		if (indices[-i + x + y] == i)
			return false;

	return true;
}

bool DFS(int row)
{
	if (row == -1)
		return false;

	for (int i = indices[row] + 1; i < n; i++)
	{
		if (set(row, i))
		{
			indices[row] = i;
			if (++row == n)
				return true;
			return DFS(row);
		}
	}

	indices[row] = -1;

	return DFS(--row);
}

int main()
{
	indices = new int[n];

	for (int i = 0; i < n; i++)
		indices[i] = -1;

	int solutions = 0;

	if (DFS(0)) {
		do
		{
			cout << "Solution " << ++solutions << ":\n";
			printBoard();
			cin.get();
		} while (DFS(n - 1));
	}

	cout << solutions << " solutions in total!" << "\n";
	cin.get();

	delete[] indices;

	return 0;
}