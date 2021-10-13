#include "GameOver.h"


void fixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}


void goToXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void textcolor(int x) {
	HANDLE  h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, x);
}


void SetWindowSize(SHORT width, SHORT height) {
	RECT rect;
	HWND console = GetConsoleWindow();
	GetWindowRect(console, &rect);
	MoveWindow(console, rect.left, rect.top, width, height, TRUE);
}


// Hidden pointer function
void noCursorType()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

// Just for fun :))
void ease(int x0, int y0, int speed)
{
	goToXY(x0, y0);

	cout << "D";
	Sleep(speed);
	cout << "o";
	Sleep(speed);
	cout << "n";
	Sleep(speed);
	cout << "'";
	Sleep(speed);
	cout << "t";
	Sleep(speed);
	cout << " ";
	Sleep(speed);

	cout << "G";
	Sleep(speed);
	cout << "i";
	Sleep(speed);
	cout << "v";
	Sleep(speed);
	cout << "e";
	Sleep(speed);
	cout << " ";
	Sleep(speed);

	cout << "U";
	Sleep(speed);
	cout << "p";
	Sleep(speed);
	cout << "!";
	Sleep(speed);

	cout << " ";
	Sleep(speed);
	cout << ":";
	Sleep(speed);
	cout << ")";
	Sleep(speed);
	cout << ")";
	Sleep(speed);
}


//********************************************************************************
// x0: Hoành độ gốc.
// y0: Tung độ gốc.
// speed: Tốc độ chữ.
// color: Màu chữ.

void gameOver(int x0, int y0, int speed, int color)
{
	ifstream fi("GameOver.txt");

	if (fi.fail()) return;

	int x, y;
	textcolor(color);

	while (!fi.eof()) {
		fi >> x >> y;
		goToXY(x0 + x, y0 + y);
		cout << char(254);
		Sleep(speed);
	}
	textcolor(15);
}