#ifndef _TICTACTOE_H_
#define _TICTACTOE_H_
#include "Library.h"

typedef pair <int, int> ii;

struct _Point {
	int X, Y;
	char opt;
};

void makeMove(char player, int row, int col);
void botPlay();
void displayWinLine(int z);
void drawX_WIN(int x, int y);
void drawO_WIN(int x, int y);
void drawDRAW(int x, int y);
void drawPopUp(int x, int y, int height, int width);
void drawStatus(int x, int y, int color);
void saveGame(int XX, int YY, int Cache, int Xscore, int Oscore, string name1, string name2, string fileName, bool vsBot);
void startGame(bool vsBot, bool isNewGame, int XX, int YY, string name1, string name2, vector<ii> Data, string fileName, int Xscore, int Oscore);


#endif