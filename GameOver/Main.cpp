#include "GameOver.h"
#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 700


void main()
{
	SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	fixConsoleWindow();
	noCursorType();

	gameOver(17, 3, 2, 146);

	ease(70, 14, 120);

	goToXY(0, 20);
}