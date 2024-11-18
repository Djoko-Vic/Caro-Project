﻿#include "Graphic.h"

#define gameTheme 15, 0

const int boardSize = 15;

extern _Point status[boardSize + 5][boardSize + 5];

struct st {
	int topLeft = 218;
	int topRight = 191;
	int botLeft = 192;
	int botRight = 217;

	int backSlash = 92;
	int vertiBar = 179;
	int horiBar = 196;

	int blank = 255;
	int dotSquare = 176;
	int boldDotSquare = 178;

} symbol;
int generateRandomNumber(int a, int b) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distr(a, b);
	return distr(gen);
}
void introAnimation(const string& filename, int delayTime, int stopTime, int x, int y) {
	decorate_draw(-1, -1, filename);
	setColor(gameTheme);
	setPos(55, 29); cout << "          ";
	setPos(55, 31); cout << "          ";
	setPos(55, 30); cout << " LOADING  ";       //33
	drawBox(65, 29, 33, 15, "                               ");
	setPos(66, 30);
	int a = 0;
	while (1) {
		int temp = rand() % 2 + 5;
		for (int i = 1; i <= temp; i++) {
			cout << char(symbol.dotSquare);
		}
		sleep_for(milliseconds(generateRandomNumber(100, 500)));
		a += temp;
		if (a > 25) break;
	}
	sleep_for(milliseconds(generateRandomNumber(50, 1000)));
	for (int i = 1; i <= 31 - a; i++) {
		cout << char(symbol.dotSquare);
	}
	int color = 11;
	atomic<bool> stopBlinking(false);
	while (!stopBlinking) {
		setColor(color, 0);
		setPos(55, 26);
		cout << "                                            "; 
		setPos(55, 28);
		cout << "                                            ";
		setPos(55, 27);
		cout << "      Press ENTER to start the game...      " << flush;
		sleep_for(milliseconds(500));
		color = (color == 11) ? 15 : 11;
		if (_kbhit()) {
			char key = _getch();
			if (key == 13) {
				stopBlinking = true;
			}
			else {
				while (_kbhit()) _getch();
			}
		}
	}
	setColor(gameTheme);
	system("cls");
}
void drawBox(int x, int y, int size, int bgColor, string text) {
	setColor(gameTheme);
	setPos(x, y);														// Top Left Corner
	cout << char(symbol.topLeft);
	for (int i = 0; i < size - 2; ++i) cout << char(symbol.horiBar);	// Horizontal Bar
	cout << char(symbol.topRight);										// Top Right Corner
	cout << char(symbol.blank);

	setPos(x, y + 1);													// Left Vertical Bar
	cout << char(symbol.vertiBar);

	setPos(x + size - 1, y + 1);										// Right Vertical Bar
	cout << char(symbol.vertiBar);
	setPos(x + size, y + 1);
	cout << char(symbol.blank);
	setPos(x + size, y + 2);
	cout << char(symbol.blank);

	setPos(x, y + 2);													// Bottom Left Corner
	cout << char(symbol.botLeft);

	for (int i = 0; i < size - 2; ++i) cout << char(symbol.horiBar);	// Horizontal Bar
	cout << char(symbol.botRight);										// Bottom Right Corner
	setPos(x + 1, y + 1);												// Print desired text
	setColor(gameTheme);
	cout << text;
	setColor(gameTheme);
}
void drawMenu1(int x, int y, int size, int bgColor, string text)
{
	setColor(gameTheme);

	setPos(x, y);														// Top Left Corner
	cout << char(symbol.topLeft);
	for (int i = 0; i < size - 2; ++i) cout << char(symbol.horiBar);	// Horizontal Bar
	cout << char(symbol.topRight);										// Top Right Corner
	cout << char(symbol.blank);

	setPos(x, y + 1);													// Left Vertical Bar
	cout << char(symbol.vertiBar);

	setPos(x + size - 1, y + 1);										// Right Vertical Bar
	cout << char(symbol.vertiBar);
	setPos(x + size, y + 1);
	cout << char(symbol.blank);
	setPos(x + size, y + 2);
	cout << char(symbol.blank);

	setPos(x, y + 2);													// Bottom Left Corner
	cout << char(symbol.botLeft);

	for (int i = 0; i < size - 2; ++i) cout << char(symbol.horiBar);	// Horizontal Bar
	cout << char(symbol.botRight);										// Bottom Right Corner

	setPos(x, y + 3);
	for (int i = 0; i < size; ++i) cout << char(symbol.blank);
	cout << char(symbol.blank);

	setPos(x + 1, y + 1);												// Print desired text
	setColor(gameTheme);
	cout << text;
	setColor(gameTheme);
}

void drawMenu2(int x, int y, int size, int bgColor, string text)
{
	setColor(gameTheme);

	setPos(x, y);
	for (int i = 0; i < size; ++i) cout << char(symbol.dotSquare);
	setPos(x, y + 1);
	for (int i = 0; i < size; ++i) cout << char(symbol.dotSquare);
	setPos(x, y + 2);
	for (int i = 0; i < size; ++i) cout << char(symbol.dotSquare);
	setPos(x - 1, y + 3);
	for (int i = 0; i <= size + 1; ++i) cout << char(symbol.backSlash);
	for (int i = 0; i <= 3; ++i) {
		setPos(x + size, y + i);
		cout << char(symbol.backSlash);
	}
	setPos(x, y - 1);
	for (int i = 0; i <= size + 1; ++i) cout << char(symbol.blank);
	for (int i = 0; i <= 3; i++) {
		setPos(x - 1, y + i);
		cout << char(symbol.blank);
	}
	setPos(x + size, y); cout << char(symbol.backSlash);
	setPos(x, y + 3); cout << char(symbol.backSlash);
	setPos(x + size, y + 3); cout << char(symbol.backSlash);

	setPos(x + 1, y + 1);
	setColor(bgColor, 0);
	cout << text;
	setColor(gameTheme);
}

void drawMenu3(int x, int y, int size, int bgColor, string text)
{
	setColor(15, 11); //12 //11 //9

	setPos(x, y);
	for (int i = 0; i < size; ++i) cout << char(symbol.boldDotSquare);
	setPos(x, y + 1);
	for (int i = 0; i < size; ++i) cout << char(symbol.boldDotSquare);
	setPos(x, y + 2);
	for (int i = 0; i < size; ++i) cout << char(symbol.boldDotSquare);
	setPos(x - 1, y + 3);
	for (int i = 0; i <= size + 1; ++i) cout << char(symbol.blank);
	for (int i = 0; i <= 3; ++i) {
		setPos(x + size, y + i);
		cout << char(symbol.blank);
	}
	setPos(x, y - 1);
	for (int i = 0; i <= size + 1; ++i) cout << char(symbol.blank);
	for (int i = 0; i <= 4; i++) {
		setPos(x - 1, y + i - 1);
		cout << char(symbol.blank);
	}

	setPos(x + 1, y + 1);
	setColor(bgColor, 0);
	cout << text;
	setColor(gameTheme);
}

// Draw Board's Outline
void drawBoardSize(int xx, int yy, int height, int width) {
	setColor(gameTheme);
	   
	setPos(xx, yy); cout << char(218);
	for (int i = 0; i < width - 2; ++i) cout << char(196);
	cout << char(191);

	for (int i = 1; i < height - 1; ++i) {
		setPos(xx, yy + i); cout << char(179);
		setPos(xx + width - 1, yy + i); cout << char(179);
	}
	setPos(xx, yy + height - 1); cout << char(192);
	for (int i = 0; i < width - 2; ++i) cout << char(196);
	cout << char(218);
}

// Draw and Update Board everytime it's been changed
void updateBoard(int x, int y, int scoreX, int scoreO, string playerA, string playerB)
{
	setColor(gameTheme);

	int newX = x - 20, newY = y - 2;
	for (int y = 0; y <= boardSize * 2; ++y)
	{
		for (int x = 0; x <= boardSize * 4; ++x)
		{
			setColor(x, y);
		}
	}
}

void drawBoard(int Xi, int Yi, string name1, string name2, int Xscore, int Oscore, string fileName) {  // Caro Board
	setColor(gameTheme);

	/*--------------------------- Draw Board ---------------------------------*/
	int XX = Xi - 14, YY = Yi - 3;		// [XX, YY] is located of pointer to draw board
	for (int y = 0; y <= 2 * boardSize; ++y) {
		for (int x = 0; x <= 4 * boardSize; ++x) {
			setPos(XX + x, YY + y);
			for (int i = 1; i < 3; i++) if (x == i * (4 * boardSize) / 3 && y == 2 * boardSize) cout << char(207);
			if (x == 0 && y == 0) cout << char(203);
			else if (x == 0 && y == 2 * boardSize) cout << char(188);
			else if (x == 4 * boardSize && y == 2 * boardSize) cout << char(202);
			else if (x % 4 == 0 && y == 0 && x != 4 * boardSize) cout << char(209);
			else if (x == 4 * boardSize && y == 0) cout << char(203);
			else if (x % 4 == 0 && y == 2 * boardSize && x != 4 * boardSize / 3 && x != 8 * boardSize / 3) cout << char(207);
			else if (x == 0 && y % 2 == 0) cout << char(199);
			else if (x == 4 * boardSize && y % 2 == 0) cout << char(182);
			else if (x % 4 == 0 && y % 2 == 0) cout << char(197);
			else if (x % 4 == 0) {
				if (x == 0 || x == 4 * boardSize) cout << char(186);
				else cout << char(179);
			}
			else if (y % 2 == 0) {
				if (y == 0 || y == 2 * boardSize) cout << char(205);
				else cout << char(196);
			}
			else cout << char(symbol.blank);
		}
	}
	for (int x = 1; x <= 6 * 4; x++) {
		setPos(XX - x, YY); cout << char(205);
		setPos(XX + 4 * boardSize + x, YY); cout << char(205);
		setPos(XX - x, YY + 2 * boardSize); cout << char(205);
		setPos(XX + 4 * boardSize + x, YY + 2 * boardSize); cout << char(205);

	}
	setPos(XX - 6 * 4 - 1, YY); cout << char(201);
	setPos(XX + 4 * boardSize + 6 * 4 + 1, YY); cout << char(187);
	setPos(XX - 6 * 4 - 1, YY + 2 * boardSize); cout << char(200);
	setPos(XX + 4 * boardSize + 6 * 4 + 1, YY + 2 * boardSize); cout << char(188);
	for (int y = 1; y <= 2 * boardSize - 1; y++) {
		setPos(XX - 6 * 4 - 1, YY + y); cout << char(186);
		setPos(XX + 4 * boardSize + 6 * 4 + 1, YY + y); cout << char(186);
	}
	/*--------------------------------------------------------------------------*/
	for (int y = 1; y <= boardSize; ++y)
		for (int x = 1; x <= boardSize; ++x) {
			status[y][x].Y = YY + (y - 1) * 2 + 1;
			status[y][x].X = XX + (x - 1) * 4 + 2;
			status[y][x].opt = '.';
		}

}

void drawLoadMenu(int XX, int YY, int size, int b_color, string str) { // 3 * size, Menu Board
	setColor(gameTheme);

	setPos(XX, YY); cout << char(201);
	for (int i = 0; i < size - 2; ++i) cout << char(205);
	cout << char(187);

	setPos(XX, YY + 1); cout << char(186);
	setPos(XX + size - 1, YY + 1); cout << char(186);

	setPos(XX, YY + 2); cout << char(200);
	for (int i = 0; i < size - 2; ++i) cout << char(205);
	cout << char(188);

	setPos(XX + 1, YY + 1);
	setColor(b_color, 0);  cout << str;
	setColor(gameTheme);
}

void drawSavedFile(int XX, int YY) {
	drawS(XX - 7, YY, gameTheme);
	drawA(XX + 2, YY, gameTheme);
	drawV(XX + 10, YY, gameTheme);
	drawE(XX + 19, YY, gameTheme);
	drawD(XX + 27, YY, gameTheme);
	drawF(XX + 42, YY, gameTheme);
	drawI(XX + 50, YY, gameTheme);
	drawL(XX + 54, YY, gameTheme);
	drawE(XX + 62, YY, gameTheme);
	drawS(XX + 70, YY, gameTheme);
	setColor(gameTheme);
}

void drawCaroMain(int XX, int YY) {
	drawC(XX - 3, YY, 15, 12);
	drawA(XX + 7, YY, 15, 12);
	drawR(XX + 17, YY, 15, 3);
	drawO(XX + 27, YY, 15, 3);
	setColor(gameTheme);
}

void newGameText(int XX, int YY) {
	drawN(XX - 25, YY, gameTheme);
	drawE(XX - 14, YY, gameTheme);
	drawW(XX - 5, YY, gameTheme);
	drawG(XX + 11, YY, gameTheme);
	drawA(XX + 21, YY, gameTheme);
	drawM(XX + 30, YY, gameTheme);
	drawE(XX + 42, YY, gameTheme);
	setColor(gameTheme);
}
void printTimeAtPosition(int x, int y, int minutes, int seconds) {
	COORD currentPos;
	saveCurPos(currentPos);
	ShowCur(0);
	setPos(x, y);
	setColor(gameTheme);
	cout << minutes << ":"
		<< (seconds < 10 ? "0" : "") << seconds << "   ";
	setPos(currentPos.X, currentPos.Y);
	ShowCur(1);
}
/*void countdownTimer(atomic<int>& timeLeftMin, atomic<int>& timeLeftSec, atomic<bool>& timeUp, atomic<bool>& turnDone) {
	while (!turnDone && (timeLeftMin > 0 || timeLeftSec > 0)) {
		printTimeAtPosition(28, 30, timeLeftMin, timeLeftSec);
		sleep_for(seconds(1));
		if (!turnDone) {
			if (timeLeftSec > 0) {
				--timeLeftSec;
			}
			else if (timeLeftMin > 0) {
				timeLeftSec = 59;
				--timeLeftMin;
			}
		}
		if (timeLeftMin <= 0 && timeLeftSec <= 0) {
			timeUp = true;
			break;
		}
	}
} */     