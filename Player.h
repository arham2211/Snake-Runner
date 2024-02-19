#include"GameObject.h"

#ifndef PLAYER_H
#define PLAYER_H

char playername[8];

int difficultyPage() {

	int count, a, b;
	bool startGame = false;
	bool enter = false;

	char username[8];
	char key = NULL;
	int i = 0;


	setbkcolor(BLACK);
	cleardevice();

	setcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	rectangle(150, 250, 390, 500);
	floodfill(160, 260, WHITE);

	circle(270, 250, 37);
	floodfill(270, 245, WHITE);

	setcolor(LIGHTRED);
	setfillstyle(SOLID_FILL, LIGHTRED);
	circle(270, 250, 32);
	floodfill(270, 245, LIGHTRED);

	setcolor(BLACK);
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 1);
	line(157, 330, 386, 330);
	rectangle(157, 360, 384, 392);

	setcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	circle(258, 244, 7);
	floodfill(258, 244, WHITE);
	circle(282, 244, 7);
	floodfill(282, 244, WHITE);

	setcolor(BLACK);
	arc(270, 260, 190, 360, 12);

	setfillstyle(SOLID_FILL, BLACK);

	circle(258, 244, 3);
	floodfill(258, 244, BLACK);
	circle(282, 244, 3);
	floodfill(282, 244, BLACK);

	setbkcolor(WHITE);
	outtextxy(162, 308, "Enter your username:");
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 2);


	settextstyle(COMPLEX_FONT, HORIZ_DIR, 1);
	outtextxy(180, 402, "* Only 8 digits");

	setcolor(LIGHTRED);
	setfillstyle(SOLID_FILL, LIGHTRED);
	arc(230, 461, 90, 270, 20);
	arc(310, 461, -90, 90, 20);
	line(230, 441, 309, 441);
	line(230, 480, 309, 480);
	floodfill(231, 450, LIGHTRED);

	setcolor(BLACK);
	setbkcolor(LIGHTRED);
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 2);
	outtextxy(240, 451, "ENTER");

	int x, y;

	setcolor(BLACK);
	setbkcolor(WHITE);
	outtextxy(218, 366, "|");


	while (!enter) {


		key = getch();

		if (key == '\r') {

			enter = true;

		}

		else if (key == '\b') {

			if (i > 0) {

				i--;
				username[i] = '\0';
				setcolor(BLACK);
				setfillstyle(SOLID_FILL, WHITE);
				bar(158, 362, 384, 392);


				setcolor(BLACK);
				setbkcolor(WHITE);
				outtextxy(218, 367, username);
			}
		}

		else if (i < 8) {


			setcolor(BLACK);
			setbkcolor(WHITE);
			username[i] = key;
			i++;

			username[i] = '\0';
			outtextxy(218, 367, username);

		}


	}

	strcpy(playername, username);

	//Easy
	setcolor(CYAN);
	setfillstyle(SOLID_FILL, CYAN);
	rectangle(580, 200, 820, 270);
	floodfill(590, 210, CYAN);

	settextstyle(BOLD_FONT, HORIZ_DIR, 5);
	setcolor(RED);
	setbkcolor(CYAN);
	outtextxy(648, 216, "EASY");


	//Medium
	setcolor(CYAN);
	setfillstyle(SOLID_FILL, CYAN);
	rectangle(580, 320, 820, 390);
	floodfill(590, 330, CYAN);

	settextstyle(BOLD_FONT, HORIZ_DIR, 5);
	setcolor(RED);
	setbkcolor(CYAN);
	outtextxy(629, 339, "MEDIUM");

	//Hard
	setcolor(CYAN);
	setfillstyle(SOLID_FILL, CYAN);
	rectangle(580, 440, 820, 510);
	floodfill(590, 450, CYAN);

	settextstyle(BOLD_FONT, HORIZ_DIR, 5);
	setcolor(RED);
	setbkcolor(CYAN);
	outtextxy(648, 459, "HARD");


	while (!startGame) {

		int x = mousex();
		int y = mousey();
		if (x >= 580 && x <= 820 && y >= 200 && y <= 270) {

			setcolor(YELLOW);
			setfillstyle(SOLID_FILL, YELLOW);
			rectangle(580, 200, 820, 270);
			floodfill(590, 210, YELLOW);

			settextstyle(BOLD_FONT, HORIZ_DIR, 5);
			setcolor(RED);
			setbkcolor(YELLOW);
			outtextxy(648, 216, "EASY");
			count = 0;
		}

		else if (x >= 580 && x <= 820 && y >= 320 && y <= 390) {

			setcolor(YELLOW);
			setfillstyle(SOLID_FILL, YELLOW);
			rectangle(580, 320, 820, 390);
			floodfill(590, 330, YELLOW);

			settextstyle(BOLD_FONT, HORIZ_DIR, 5);
			setcolor(RED);
			setbkcolor(YELLOW);
			outtextxy(629, 339, "MEDIUM");
			count = 1;
		}

		else if (x >= 580 && x <= 820 && y >= 440 && y <= 510) {

			setcolor(YELLOW);
			setfillstyle(SOLID_FILL, YELLOW);
			rectangle(580, 440, 820, 510);
			floodfill(590, 450, YELLOW);

			settextstyle(BOLD_FONT, HORIZ_DIR, 5);
			setcolor(RED);
			setbkcolor(YELLOW);
			outtextxy(648, 459, "HARD");
			count = 2;
		}

		else
		{
			if (count == 0)
			{
				setcolor(CYAN);
				setfillstyle(SOLID_FILL, CYAN);
				rectangle(580, 200, 820, 270);
				floodfill(590, 210, CYAN);

				settextstyle(BOLD_FONT, HORIZ_DIR, 5);
				setcolor(RED);
				setbkcolor(CYAN);
				outtextxy(648, 216, "EASY");

			}

			else if (count == 1) {

				setcolor(CYAN);
				setfillstyle(SOLID_FILL, CYAN);
				rectangle(580, 320, 820, 390);
				floodfill(590, 330, CYAN);

				settextstyle(BOLD_FONT, HORIZ_DIR, 5);
				setcolor(RED);
				setbkcolor(CYAN);
				outtextxy(629, 339, "MEDIUM");
			}

			else if (count == 2) {

				setcolor(CYAN);
				setfillstyle(SOLID_FILL, CYAN);
				rectangle(580, 440, 820, 510);
				floodfill(590, 450, CYAN);

				settextstyle(BOLD_FONT, HORIZ_DIR, 5);
				setcolor(RED);
				setbkcolor(CYAN);
				outtextxy(648, 459, "HARD");

			}
		}
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, a, b);
			if (x >= 580 && x <= 820 && y >= 200 && y <= 270) {
				startGame = true;
				return count;
			}

			else if (x >= 580 && x <= 820 && y >= 320 && y <= 390) {
				startGame = true;
				return count;
			}

			else if (x >= 580 && x <= 820 && y >= 440 && y <= 510) {
				startGame = true;
				return count;
			}
		}


	}
}

class Player :public GameObject {

public:

	char* name;
	int movecount;
	int limitedroll;
	int blocked;
	int	playerTrack;
	int speed;


	Player() :GameObject(476, 527) {

		name = playername;
		blocked = 0;
		playerTrack = 8;
		speed=0;
		movecount = 0;

	}

	void draw() {

		setcolor(RED);
		setfillstyle(SOLID_FILL, RED);
		circle(x, y, 20);
		floodfill(x, y, RED);
	}

	void draw(int color) {

		setcolor(color);
		setfillstyle(SOLID_FILL, color);
		circle(x, y, 20);
		floodfill(x, y, color);
	}

};


#endif // PLAYER_H
