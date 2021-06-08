#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

#include "Console.h"

using namespace std;

//0은 벽 1은 길
char Lv1Map[13][16] =
{
	"000000000000000",
	"000000000000000",
	"0001121121111&0",
	"000200100020000",
	"000111101110000",
	"@11100101010000",
	"000200102010000",
	"000121111210000",
	"000100001010000",
	"000111211210000",
	"000000000000000",
	"000000000000000"
};

char Lv2Map[13][16] =
{
	"000000001000000",
	"000000001000000",
	"0001111211111&0",
	"000202002010000",
	"@11101111020000",
	"000111001110000",
	"000101002010000",
	"000201111110000",
	"000101002020000",
	"000121121111111",
	"000100000000000",
	"000100000000000"
};

char Lv3Map[13][16] =
{
	"000001000000000",
	"000001000000000",
	"1111211112111&0",
	"000101020010000",
	"000121112110000",
	"000202010020000",
	"@11111010010000",
	"000101111110000",
	"000202020020000",
	"000111211110000",
	"000000000010000",
	"000000000010000"
};

int currentX, currentY;
int x, y;
int n = 1;

void displayScreen(int num)
{
	system(" mode  con lines=28   cols=42 ");

	if (num == 1)
	{
		for (y = 0; y < 13; y++)
		{
			for (x = 0; x < 16; x++)
			{
				gotoXY(x + 5, y + 2);
				if (Lv1Map[y][x] == '1')
				{
					_putch(Lv1Map[y][x] = ' ');
				}
				if (Lv1Map[y][x] == '0')
				{
					_putch(Lv1Map[y][x] = '#');
				}
				if (Lv1Map[y][x] == '2')
				{
					setTextColor(12);
					_putch(Lv1Map[y][x] = '^');
					setTextColor(7);
				}
				if (Lv1Map[y][x] == '@')
				{
					setTextColor(12);
					_putch(Lv1Map[y][x] = '@');
					setTextColor(7);
				}
			}
		}

		for (y = 0; y < 13; y++)
		{
			for (x = 0; x < 15; x++)
			{
				if (Lv1Map[y][x] == '&')
				{
					currentX = x;
					currentY = y;
					Lv1Map[y][x] = ' ';
				}
			}
		}
	}

	if (num == 2)
	{
		for (y = 0; y < 13; y++)
		{
			for (x = 0; x < 16; x++)
			{
				gotoXY(x + 5, y + 2);
				if (Lv2Map[y][x] == '1')
				{
					_putch(Lv2Map[y][x] = ' ');
				}
				if (Lv2Map[y][x] == '0')
				{
					_putch(Lv2Map[y][x] = '#');
				}
				if (Lv2Map[y][x] == '2')
				{
					setTextColor(12);
					_putch(Lv2Map[y][x] = '^');
					setTextColor(7);
				}
				if (Lv2Map[y][x] == '@')
				{
					setTextColor(12);
					_putch(Lv2Map[y][x] = '@');
					setTextColor(7);
				}
			}
		}

		for (y = 0; y < 10; y++)
		{
			for (x = 0; x < 15; x++)
			{
				if (Lv2Map[y][x] == '&')
				{
					currentX = x;
					currentY = y;
					Lv2Map[y][x] = ' ';
				}
			}
		}
	}

	if (num == 3)
	{
		for (y = 0; y < 13; y++)
		{
			for (x = 0; x < 16; x++)
			{
				gotoXY(x + 5, y + 2);
				if (Lv3Map[y][x] == '1')
				{
					_putch(Lv3Map[y][x] = ' ');
				}
				if (Lv3Map[y][x] == '0')
				{
					_putch(Lv3Map[y][x] = '#');
				}
				if (Lv3Map[y][x] == '2')
				{
					setTextColor(12);
					_putch(Lv3Map[y][x] = '^');
					setTextColor(7);
				}
				if (Lv3Map[y][x] == '@')
				{
					setTextColor(12);
					_putch(Lv3Map[y][x] = '@');
					setTextColor(7);
				}
			}
		}

		for (y = 0; y < 13; y++)
		{
			for (x = 0; x < 16; x++)
			{
				if (Lv3Map[y][x] == '&')
				{
					currentX = x + 5;
					currentY = y + 2;
					Lv3Map[y][x] = ' ';
				}
			}
		}
	}
}

void initScreen(int num)
{
	if (num == 1)
	{
		for (y = 0; y < 13; y++)
		{
			for (x = 0; x < 16; x++)
			{
				gotoXY(x + 5, y + 2);
				if (Lv1Map[y][x] == '^')
				{
					setTextColor(14);
					_putch(Lv1Map[y][x]);
					setTextColor(7);
				}
				else
				{
					_putch(Lv1Map[y][x]);
				}
			}
		}
	}

	if (num == 2)
	{
		for (y = 0; y < 13; y++)
		{
			for (x = 0; x < 16; x++)
			{
				gotoXY(x, y);
				if (Lv2Map[y][x] == '^')
				{
					setTextColor(14);
					_putch(Lv2Map[y][x]);
					setTextColor(7);
				}
				else
				{
					_putch(Lv2Map[y][x]);
				}
			}
		}
	}

	if (num == 3)
	{
		for (y = 0; y < 13; y++)
		{
			for (x = 0; x < 16; x++)
			{
				gotoXY(x, y);
				if (Lv3Map[y][x] == '^')
				{
					setTextColor(8);
					_putch(Lv3Map[y][x]);
					setTextColor(7);
				}
				else
				{
					_putch(Lv3Map[y][x]);
				}
			}
		}
	}

	gotoXY(currentX + 5, currentY + 2);
	_putch('&');

	gotoXY(18, 13);
}

int dir_x, dir_y;

void banana(int _n, int _x, int _y)
{
	if (_n == 1)
	{
		if (Lv1Map[currentY][currentX] == '^')
		{
			while (Lv1Map[currentY + _y][currentX + _x] != '#')
			{
				currentX += dir_x;
				currentY += dir_y;

				initScreen(n);
				Sleep(30);
			}
		}
	}
	if (_n == 2)
	{
		if (Lv2Map[currentY][currentX] == '^')
		{
			while (Lv2Map[currentY + _y][currentX + _x] != '#')
			{
				currentX += dir_x;
				currentY += dir_y;

				initScreen(n);
				Sleep(30);
			}
		}
	}
	if (_n == 3)
	{
		if (Lv3Map[currentY][currentX] == '^')
		{
			while (Lv3Map[currentY + _y][currentX + _x] != '#')
			{
				currentX += dir_x;
				currentY += dir_y;
				
				initScreen(n);
				Sleep(30);
			}
		}
	}
}

void move(int dir, int num)
{
	dir_x = 0;
	dir_y = 0;

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

	if (num == 1)
	{
		if (Lv1Map[currentY + dir_y][currentX + dir_x] != '#')
		{
			currentX += dir_x;
			currentY += dir_y;
		}
	}

	if (num == 2)
	{
		if (Lv2Map[currentY + dir_y][currentX + dir_x] != '#')
		{
			currentX += dir_x;
			currentY += dir_y;
		}
	}

	if (num == 3)
	{
		if (Lv3Map[currentY + dir_y][currentX + dir_x] != '#')
		{
			currentX += dir_x;
			currentY += dir_y;
		}
	}

	banana(num, dir_x, dir_y);
}


int main()
{
	PlaySound("C:\\Users\\ROG\\source\\repos\\GamePrgPj(Maze)\\GamePrgPj(Maze)\\BGM LAB - Take a break.wav", 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
	int key;
	displayScreen(n);

	clrscr();

	while (true)
	{
		initScreen(n);

		key = _getch();
		key = tolower(key);

		if (key == 0xE0 || key == 0)
		{
			key = _getch();

			switch (key)
			{
			case LEFT:
			case RIGHT:
			case UP:
			case DOWN:
				move(key, n);
				break;
			}
		}
		else
		{
			if (key == 'q')
			{
				clrscr();
				gotoXY(8, 3);
				cout << "게임을 종료하시겠습니까?";
				gotoXY(7, 4);
				cout << ">> 1 : 종료    2 : 취소 <<" << endl;

				key = _getch();

				if (key == '1')
				{
					clrscr();
					gotoXY(7, 3);
					cout << "게임을 종료하였습니다";
					exit(0);
				}
				else if (key == '2')
				{
					return main();
				}
			}

			if (key == 'r')
			{
				return main();
			}
		}

		if (n == 1)
		{
			if (Lv1Map[currentY][currentX] == '@')
			{
				n++;

				displayScreen(n);

				clrscr();
			}
		}

		if (n == 2)
		{
			if (Lv2Map[currentY][currentX] == '@')
			{
				n++;

				displayScreen(n);

				clrscr();
			}
		}

		if (n == 3)
		{
			if (Lv3Map[currentY][currentX] == '@')
			{
				clrscr();
				gotoXY(5, 7);
				cout << "게임 클리어\n" << endl;
				exit(0);
			}
		}
	}
	return 0;
}