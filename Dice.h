#include"GameObject.h"

#ifndef DICE_H
#define DICE_H

class Dice :public GameObject {

public:

	Dice() :GameObject(825, 250) {}

	void draw() {}

	void draw(int num) {

		setfillstyle(SOLID_FILL, WHITE);
		setcolor(RED);
		bar(x, y, x + 50, y + 50);
		for (int i = 0; i < 2; i++) {

			rectangle(x + i, y - i, x + 50 + i, y + 50 + i);
			line(x + 25, y - 15 + i, x + 75, y - 15 + i);

		}

		for (int i = 0; i < 3; i++) {

			line(x + i, y, x + 25 + i, y - 15);
			line(x + 50 + i, y, x + 75 + i, y - 15);
			line(x + 75 + i, y - 15, x + 75 + i, y + 32);
			line(x + 50, y + 49 + i, x + 75, y + 31 + i);

		}

		setfillstyle(SOLID_FILL, WHITE);
		floodfill(864, 243, RED);
		floodfill(890, 268, RED);

		setfillstyle(SOLID_FILL, RED);

		if (num == 1) {
			circle(x + 25, y + 25, 5);
			floodfill(x + 25, y + 22, RED);

		}

		else if (num == 2) {
			circle(x + 15, y + 15, 5);
			floodfill(x + 15, y + 15, RED);

			circle(x + 35, y + 35, 5);
			floodfill(x + 35, y + 35, RED);
		}

		else if (num == 3) {
			circle(x + 15, y + 15, 5);
			floodfill(x + 15, y + 15, RED);

			circle(x + 25, y + 25, 5);
			floodfill(x + 25, y + 25, RED);

			circle(x + 35, y + 35, 5);
			floodfill(x + 35, y + 35, RED);
		}

		else if (num == 4) {
			circle(x + 15, y + 15, 5);
			floodfill(x + 15, y + 15, RED);

			circle(x + 35, y + 15, 5);
			floodfill(x + 35, y + 15, RED);

			circle(x + 15, y + 35, 5);
			floodfill(x + 15, y + 35, RED);

			circle(x + 35, y + 35, 5);
			floodfill(x + 35, y + 35, RED);
		}

		else if (num == 5) {
			circle(x + 15, y + 15, 5);
			floodfill(x + 15, y + 15, RED);

			circle(x + 35, y + 15, 5);
			floodfill(x + 35, y + 15, RED);

			circle(x + 25, y + 25, 5);
			floodfill(x + 25, y + 25, RED);

			circle(x + 15, y + 35, 5);
			floodfill(x + 15, y + 35, RED);

			circle(x + 35, y + 35, 5);
			floodfill(x + 35, y + 35, RED);
		}

		else if (num == 6) {

			circle(x + 15, y + 10, 5);
			floodfill(x + 15, y + 10, RED);

			circle(x + 35, y + 10, 5);
			floodfill(x + 35, y + 10, RED);

			circle(x + 15, y + 25, 5);
			floodfill(x + 15, y + 25, RED);

			circle(x + 35, y + 25, 5);
			floodfill(x + 35, y + 25, RED);

			circle(x + 15, y + 40, 5);
			floodfill(x + 15, y + 40, RED);

			circle(x + 35, y + 40, 5);
			floodfill(x + 35, y + 40, RED);

		}
	}



	void drawRollRectanlge() {


		setfillstyle(SOLID_FILL, WHITE);
		setcolor(WHITE);
		rectangle(800, 331, 919, 384);
		floodfill(801, 332, WHITE);

		setfillstyle(SOLID_FILL, DARKGRAY);
		setcolor(DARKGRAY);
		rectangle(802, 333, 917, 382);
		floodfill(804, 335, DARKGRAY);

		setfillstyle(SOLID_FILL, LIGHTRED);
		setcolor(LIGHTRED);
		rectangle(810, 340, 910, 375);
		floodfill(811, 345, LIGHTRED);


		settextstyle(2, HORIZ_DIR, 6);
		setbkcolor(LIGHTRED);
		setcolor(BLACK);
		outtextxy(815, 352, "ROLL DICE");


	}


};

#endif // DICE_H
