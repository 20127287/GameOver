#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;


void fixConsoleWindow();

void goToXY(int x, int y);

void textcolor(int x);

void noCursorType();

void SetWindowSize(SHORT width, SHORT height);

void ease(int x0, int y0, int speed);

void gameOver(int x0, int y0, int speed, int color);