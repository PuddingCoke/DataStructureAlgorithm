#include<stdio.h>
#include<Windows.h>

#define W '*'
#define S ' '
#define C '%'
#define O 'O'

int finished = 0;

int x = 1, y = 7;
int outX = 5, outY = 1;

char maze[9][11] =
{
	{S,S,S,S,W,W,W,S,S,S,S},
	{S,S,S,S,W,S,W,S,S,S,S},
	{S,S,S,S,W,S,W,S,S,S,S},
	{W,W,W,W,W,S,W,W,W,W,W},
	{W,S,S,S,S,S,S,S,S,S,W},
	{W,S,W,W,W,S,W,W,W,S,W},
	{W,S,W,S,W,S,W,S,W,S,W},
	{W,S,W,S,W,S,W,S,W,S,W},
	{W,W,W,S,W,W,W,S,W,W,W}
};

int mazeCount[9][11] = { 0 };

void printMaze()
{
	maze[y][x] = C;

	for (size_t i = 0; i < 9; i++)
	{
		for (size_t j = 0; j < 11; j++)
		{
			printf("%c ", maze[i][j]);
		}
		printf("\n");
	}

	maze[y][x] = S;

}

enum Dir
{
	UP, DOWN, LEFT, RIGHT
} dir = UP;

void move()
{
	if (x == outX && y == outY)
	{
		finished = 1;
		return;
	}

	int turned = 0;

	switch (dir)
	{
	case UP:
		if (maze[y][x + 1] == ' ' && mazeCount[y][x + 1] == 0)
		{
			mazeCount[y][x]--;
			dir = RIGHT;
			turned = 1;
		}
		break;
	case DOWN:
		if (maze[y][x - 1] == ' ' && mazeCount[y][x - 1] == 0)
		{
			mazeCount[y][x]--;
			dir = LEFT;
			turned = 1;
		}
		break;
	case LEFT:
		if (maze[y - 1][x] == ' ' && mazeCount[y - 1][x] == 0)
		{
			mazeCount[y][x]--;
			dir = UP;
			turned = 1;
		}
		break;
	case RIGHT:
		if (maze[y + 1][x] == ' ' && mazeCount[y + 1][x] == 0)
		{
			mazeCount[y][x]--;
			dir = DOWN;
			turned = 1;
		}
	}

	if (turned)
		return;

	switch (dir)
	{
	case UP:
		if (maze[y][x + 1] == W && maze[y - 1][x] == W)
		{
			dir = LEFT;
			turned = 1;
		}
		break;
	case DOWN:
		if (maze[y][x - 1] == W && maze[y + 1][x] == W)
		{
			dir = RIGHT;
			turned = 1;
		}
		break;
	case LEFT:
		if (maze[y - 1][x] == W && maze[y][x - 1] == W)
		{
			dir = DOWN;
			turned = 1;
		}
		break;
	case RIGHT:
		if (maze[y][x + 1] == W && maze[y + 1][x] == W)
		{
			dir = UP;
			turned = 1;
		}
		break;
	}

	if (turned)
		return;

	switch (dir)
	{
	case UP:
		if (maze[y - 1][x] == W)
		{
			dir = DOWN;
			turned = 1;
		}
		break;
	case DOWN:
		if (maze[y + 1][x] == W)
		{
			dir = UP;
			turned = 1;
		}
		break;
	case LEFT:
		if (maze[y][x - 1] == W)
		{
			dir = RIGHT;
			turned = 1;
		}
		break;
	case RIGHT:
		if (maze[y][x + 1] == W)
		{
			dir = LEFT;
			turned = 1;
		}
		break;
	}

	if (turned)
		return;

	switch (dir)
	{
	case UP:
		mazeCount[y--][x]++;
		break;
	case DOWN:
		mazeCount[y++][x]++;
		break;
	case LEFT:
		mazeCount[y][x--]++;
		break;
	case RIGHT:
		mazeCount[y][x++]++;
	}


}

int main()
{
	do
	{
		printMaze();
		move();
		Sleep(100);
		system("cls");
	} while (!finished);
	return 0;
}