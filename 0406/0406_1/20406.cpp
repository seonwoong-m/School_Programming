#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>

using namespace std;

#define UP		72
#define DOWN	80
#define LEFT	75
#define RIGHT	77

int currentX, currentY;

char ShowMap[20][21] = {
	"++++++++++++++++++++",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"++++++++++++++++++++",
};

void gotoXY(int x, int y)
{
	HANDLE hOut;
	COORD Cur;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(hOut, Cur);
}

void displayScreen()
{
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 20; x++)
		{ 
			gotoXY(x, y);
			_putch(ShowMap[y][x]);
		}
	}

	gotoXY(currentX, currentY);
	_putch('0');
	gotoXY(30, 2);
	cout << "Q : 종료";
	gotoXY(30, 3);
	cout << "A : 상하좌우 + 를 . 으로 변경";
	gotoXY(30, 4);
	cout << "B : 외곽 + 를 좌우 대칭으로 . 으로 변경 (포탈기능)";
}

void move(int dir)
{
	int dir_x = 0, dir_y = 0;

	switch (dir)
	{
	case LEFT:
		dir_x = -1;
		break;
	case RIGHT:
		dir_x = 1;
		break;
	case UP:
		dir_y = -1;
		break;
	case DOWN:
		dir_y = 1;
		break;
	}

	if (ShowMap[currentY + dir_y][currentX + dir_x] != '+')
	{
		currentX += dir_x;
		currentY += dir_y;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int ch;
	currentX = 1;
	currentY = 1;

	int r = 0;
	int l = 0;

	for (int i = 0; i <= 10; i++)
	{
		r = rand() % 19 + 1;
		l = rand() % 19 + 1;

		_putch(ShowMap[r][l] = '+');
	}

	while (true)
	{
		displayScreen();

		

		ch = _getch();
		
		if (ch == 0xE0 || ch == 0)
		{
			ch = _getch();
			switch (ch)
			{
			case LEFT:
			case RIGHT:
			case UP:
			case DOWN:
				move(ch);
				break;
			}
		}
		else
		{
			ch = tolower(ch);

			if (ch == 'q')
			{
				exit(0);
			}
			else if (ch == 'z')
			{
				ShowMap[currentY][currentX] = 'X';
			}
			else if (ch == 'a' && currentY > 0 && currentY < 19 && currentX > 0 && currentX < 19)
			{
				
				if (ShowMap[currentY - 1][currentX] != '.' || ShowMap[currentY + 1][currentX] != '.' || ShowMap[currentY][currentX - 1] != '.' || ShowMap[currentY][currentX + 1] != '.')
				{
					if (currentY - 1 <= 0)
					{
						if(ShowMap[currentY - 1][currentX] != '.')
							ShowMap[currentY - 1][currentX] = '+';
						else
							ShowMap[currentY - 1][currentX] = '.';
					}
					else
						ShowMap[currentY - 1][currentX] = '.';

					if (currentY + 1 >= 18)
					{
						if (ShowMap[currentY + 1][currentX] != '.')
							ShowMap[currentY + 1][currentX] = '+';
						else
							ShowMap[currentY + 1][currentX] = '.';
					}
					else
						ShowMap[currentY + 1][currentX] = '.';

					if (currentX - 1 <= 0)
					{
						if (ShowMap[currentY][currentX - 1] != '.')
							ShowMap[currentY][currentX - 1] = '+';
						else
							ShowMap[currentY][currentX - 1] = '.';
					}
					else
						ShowMap[currentY][currentX - 1] = '.';

					if (currentX + 1 >= 18)
					{
						if (ShowMap[currentY][currentX + 1] != '.')
							ShowMap[currentY][currentX + 1] = '+';
						else
							ShowMap[currentY][currentX + 1] = '.';
					}
					else
						ShowMap[currentY][currentX + 1] = '.';
				}
			}
			else if (ch == 'b')
			{
				if (currentY == 1 || currentY == 18)
				{
					ShowMap[0][currentX] = '.';
					ShowMap[19][currentX] = '.';
				}

				if (currentX == 1 || currentX == 18)
				{
					ShowMap[currentY][0] = '.';
					ShowMap[currentY][19] = '.';
				}

			}
		}

		if (currentX < 0)
			currentX = 19;
		else if (currentX > 19)
			currentX = 0;

		if (currentY < 0)
			currentY = 19;
		else if (currentY > 19)
			currentY = 0;
	}

	return 0;
}