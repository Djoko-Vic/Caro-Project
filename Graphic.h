#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_
#include "Library.h"
#include "Console.h"
#include "Tictactoe.h"
#include "Draw.h"
#include <thread>
#include <chrono>

using namespace this_thread;
using namespace chrono;

void introAnimation(const string& filename, int delayTime, int stopTime, int x, int y);
void drawMenu1(int x, int y, int size, int bgColor, string text);
void drawMenu2(int x, int y, int size, int bgColor, string text);
void drawMenu3(int x, int y, int size, int bgColor, string text);
void drawBoardSize(int x, int y, int height, int width);
void drawBoard(int Xi, int Yi, string name1, string name2, int Xscore, int Oscore, string fileName);
void drawBox(int x, int y, int size, int bgColor, string text);
void drawLoadMenu(int XX, int YY, int size, int b_color, string str = "");
void drawSavedFile(int XX, int YY);
void drawCaroMain(int XX, int YY);
void newGameText(int XX, int YY);
void printTimeAtPosition(int x, int y, int minutes, int seconds);

#endif