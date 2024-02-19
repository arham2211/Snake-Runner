
#ifndef GAME_BOARD_H
#define GAME_BOARD_H

class GameBoard {
public:

	int respawn;
	int respawn2;

	GameBoard() {
		respawn = 0;
		respawn2 = 0;
	}

	void drawGameBoard() {

		settextstyle(3, HORIZ_DIR, 3);
		setbkcolor(3);
		cleardevice();
		setcolor(BLACK);

		int a = 100, b = 550, count1 = 0, count2 = 0;

		for (int i = 0; i < 10; i++) {

			for (int j = 0; j < 10; j++) {

				rectangle(a, b, a + 50, b - 50);
				rectangle(a + 1, b - 1, a + 51, b - 51);
				rectangle(a + 2, b - 2, a + 52, b - 52);
				char str[3];

				if (i % 2 == 0) {
					count1 = count1 + 1;
					count2 = count2 + 1;
					itoa(count2, str, 10);

				}

				else {

					count2 = count2 + 1;
					itoa(count1, str, 10);
					count1 = count1 - 1;

				}

				outtextxy(a + 11, b - 30, str);

				if ((i + j) % 2 == 0) {

					setfillstyle(SOLID_FILL, GREEN);
					setbkcolor(GREEN);
					floodfill(a + 3, b - 3, BLACK);


					rectangle(a, b, a + 50, b - 50);

				}
				else {

					setfillstyle(SOLID_FILL, WHITE);
					floodfill(a + 3, b - 3, BLACK);
					floodfill(a + 19, b - 19, BLACK);
					floodfill(a + 28, b - 17, BLACK);
					floodfill(a + 28, b - 21, BLACK);
					floodfill(a + 40, b - 18, BLACK);
					floodfill(a + 17, b - 21, BLACK);
					floodfill(a + 16, b - 15, BLACK);
					floodfill(a + 16, b - 17, BLACK);


					rectangle(a, b, a + 50, b - 50);
				}

				a += 50;
			}
			count1 = count1 + 10;

			a = 100;
			b -= 50;

		}

		setfillstyle(SOLID_FILL, WHITE);
		rectangle(919, 629, 1021, 671);
		rectangle(920, 630, 1020, 670);
		floodfill(922, 632, BLACK);

		settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
		setbkcolor(WHITE);
		outtextxy(940, 641, "EXIT");
		setbkcolor(3);

		if (respawn == 1) {
			drawHearts();
		}
		if (respawn2 == 1) {
			drawHearts2();
		}

	}

	void drawHearts() {

		setcolor(RED);

		// Draw the left half of the heart
		for (int i = -45; i < 0; i++) {
			float x = 16 * pow(sin(i), 3);
			float y = -13 * cos(i) + 5 * cos(2 * i) + 2 * cos(3 * i) + cos(4 * i);
			float x_next = 16 * pow(sin(i + 1), 3);
			float y_next = -13 * cos(i + 1) + 5 * cos(2 * (i + 1)) + 2 * cos(3 * (i + 1)) + cos(4 * (i + 1));
			line(x + 232, y + 608, x_next + 232, y_next + 608);
		}

		// Draw the right half of the heart
		for (int i = 0; i <= 45; i++) {
			float x = 16 * pow(sin(i), 3);
			float y = -13 * cos(i) + 5 * cos(2 * i) + 2 * cos(3 * i) + cos(4 * i);
			float x_next = 16 * pow(sin(i + 1), 3);
			float y_next = -13 * cos(i + 1) + 5 * cos(2 * (i + 1)) + 2 * cos(3 * (i + 1)) + cos(4 * (i + 1));
			line(x + 232, y + 608, x_next + 232, y_next + 608);
		}


		setfillstyle(SOLID_FILL, RED);

		floodfill(181, 609, RED);

	}

	void drawHearts2() {

		setcolor(RED);

		// Draw the left half of the heart
		for (int i = -45; i < 0; i++) {
			float x = 16 * pow(sin(i), 3);
			float y = -13 * cos(i) + 5 * cos(2 * i) + 2 * cos(3 * i) + cos(4 * i);
			float x_next = 16 * pow(sin(i + 1), 3);
			float y_next = -13 * cos(i + 1) + 5 * cos(2 * (i + 1)) + 2 * cos(3 * (i + 1)) + cos(4 * (i + 1));
			line(x + 232, y + 658, x_next + 232, y_next + 658);
		}

		// Draw the right half of the heart
		for (int i = 0; i <= 45; i++) {
			float x = 16 * pow(sin(i), 3);
			float y = -13 * cos(i) + 5 * cos(2 * i) + 2 * cos(3 * i) + cos(4 * i);
			float x_next = 16 * pow(sin(i + 1), 3);
			float y_next = -13 * cos(i + 1) + 5 * cos(2 * (i + 1)) + 2 * cos(3 * (i + 1)) + cos(4 * (i + 1));
			line(x + 232, y + 658, x_next + 232, y_next + 658);
		}


		setfillstyle(SOLID_FILL, RED);

		floodfill(181, 659, RED);

	}



};

#endif // GAME_BOARD_H
