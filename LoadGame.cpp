#include "Library.h"
#include "Maincaro.h"
#include "Loadgame.h"
#include "Console.h"
#include "Tictactoe.h"
#include "Graphic.h"

vector<string> fileSave;

void loadGame(int XX, int YY) {
	struct loadMenu {
		int X, Y, size, b_color;
		string str;

		void draw() {
			drawLoadMenu(X, Y, size, b_color, str);
		}
	};

	int size = min((int)fileSave.size() - 1, 8);
	loadMenu s1[10], s2[10];
	for (int i = 0; i < 9; ++i) {
		s1[i] = { XX - 30 + 30 * (i / 3), YY + 5 + (i % 3) * 4, 20, 11, "      EMPTY       " };
		s2[i] = { XX - 30 + 30 * (i / 3), YY + 5 + (i % 3) * 4, 20, 8, "" };

		if (i <= size) {
			string tmp = fileSave[i];
			int siz = 8 - (int)tmp.size();

			for (int j = 1; 2 * j <= siz; ++j)
				tmp = ' ' + tmp + ' ';
			if (siz & 1) tmp += ' ';

			s1[i].str = "  " + tmp + "  ";
			s2[i].str = ">>" + tmp + "<<";
			s1[i].b_color = 15;
		}
	}

	system("cls");

	drawSavedFile(XX - 26, YY - 9);

	int S = min(0, size);
	while (true) {
		for (int i = 0; i < 9; ++i)
			s1[i].draw();
		if (S != -1) s2[S].draw();
	}
}