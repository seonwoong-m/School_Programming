#pragma once

#include <iostream>
#include <Windows.h>
#include <conio.h>

#define UP		72
#define DOWN	80
#define LEFT	75
#define RIGHT	77

extern void gotoXY(int x, int y);
extern void setTextColor(int color);
extern void clrscr();