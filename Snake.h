#include"GameObject.h"

#ifndef SNAKE_H
#define SNAKE_H

class Snake :public GameObject {

public:

	int snakeTrack;
	int freeze;

	Snake() :GameObject(76, 527) {

		freeze = 0;
		snakeTrack = 0;
	}

	void draw() {

		setcolor(BLUE);
		setfillstyle(SOLID_FILL, YELLOW);
		circle(x, y, 6);
		floodfill(x, y, BLUE);

		setfillstyle(SOLID_FILL, MAGENTA);

		circle(x - 12, y, 6);
		floodfill(x - 12, y, BLUE);

		circle(x - 24, y, 6);
		floodfill(x - 24, y, BLUE);

		circle(x - 36, y, 6);
		floodfill(x - 36, y, BLUE);

		circle(x - 48, y, 6);
		floodfill(x - 48, y, BLUE);

		circle(x - 60, y, 6);
		floodfill(x - 60, y, BLUE);

	}

	void moveSnake() {

		if (freeze == 1) {

			setcolor(BLUE);
			if (snakeTrack == 9 || snakeTrack == 69) {

				setfillstyle(SOLID_FILL, YELLOW);
				circle(x, y, 6);
				floodfill(x, y, BLUE);
				setfillstyle(SOLID_FILL, MAGENTA);

				for (int i = 1; i < 6; i++) {

					circle(x + (12 * i), y, 6);
					floodfill(x + (12 * i), y, BLUE);
				}
			}

			else if (snakeTrack == 18 || snakeTrack == 78) {

				setfillstyle(SOLID_FILL, YELLOW);
				circle(x, y, 6);
				floodfill(x, y, BLUE);
				setfillstyle(SOLID_FILL, MAGENTA);

				for (int i = 1; i < 6; i++) {

					circle(x, y + (12 * i), 6);
					floodfill(x, y + (12 * i), BLUE);
				}
			}

			else if (snakeTrack == 30 || snakeTrack == 90) {

				setfillstyle(SOLID_FILL, YELLOW);
				circle(x, y, 6);
				floodfill(x, y, BLUE);
				setfillstyle(SOLID_FILL, MAGENTA);

				for (int i = 1; i < 6; i++) {

					circle(x + (12 * i), y, 6);
					floodfill(x + (12 * i), y, BLUE);

				}
			}

			else if (snakeTrack == 39) {

				setfillstyle(SOLID_FILL, YELLOW);
				circle(x, y, 6);
				floodfill(x, y, BLUE);
				setfillstyle(SOLID_FILL, MAGENTA);

				for (int i = 1; i < 6; i++) {

					circle(x - (12 * i), y, 6);
					floodfill(x - (12 * i), y, BLUE);
				}
			}

			else if (snakeTrack == 48) {

				setfillstyle(SOLID_FILL, YELLOW);
				circle(x, y, 6);
				floodfill(x, y, BLUE);
				setfillstyle(SOLID_FILL, MAGENTA);

				for (int i = 1; i < 6; i++) {

					circle(x, y + (12 * i), 6);
					floodfill(x, y + (12 * i), BLUE);
				}
			}

			else if (snakeTrack == 60) {

				setfillstyle(SOLID_FILL, YELLOW);
				circle(x, y, 6);
				floodfill(x, y, BLUE);
				setfillstyle(SOLID_FILL, MAGENTA);

				for (int i = 1; i < 6; i++) {

					circle(x - (12 * i), y, 6);
					floodfill(x - (12 * i), y, BLUE);

				}
			}

			else if ((snakeTrack < 9) || (snakeTrack > 20 && snakeTrack < 30) || (snakeTrack > 41 && snakeTrack < 48) || (snakeTrack > 60 && snakeTrack < 69) || (snakeTrack > 80 && snakeTrack < 90)) {

				setfillstyle(SOLID_FILL, YELLOW);
				circle(x, y, 6);
				floodfill(x, y, BLUE);
				setfillstyle(SOLID_FILL, MAGENTA);

				for (int i = 1; i < 6; i++) {

					circle(x - (12 * i), y, 6);
					floodfill(x - (12 * i), y, BLUE);
				}

			}

			else if ((snakeTrack > 11 && snakeTrack < 18) || (snakeTrack > 30 && snakeTrack < 39) || (snakeTrack > 50 && snakeTrack < 60) || (snakeTrack > 71 && snakeTrack < 78) || (snakeTrack > 90 && snakeTrack < 99)) {



				setfillstyle(SOLID_FILL, YELLOW);
				circle(x, y, 6);
				floodfill(x, y, BLUE);
				setfillstyle(SOLID_FILL, MAGENTA);

				for (int i = 1; i < 6; i++) {

					circle(x + (12 * i), y, 6);
					floodfill(x + (12 * i), y, BLUE);
				}

			}


			freeze = 0;
			return;
		}

		setcolor(BLUE);

		if (snakeTrack == 9 || snakeTrack == 69) {

			y -= 50;

			setfillstyle(SOLID_FILL, YELLOW);
			circle(x, y, 6);
			floodfill(x, y, BLUE);
			setfillstyle(SOLID_FILL, MAGENTA);

			for (int i = 1; i < 6; i++) {

				circle(x + (12 * i), y, 6);
				floodfill(x + (12 * i), y, BLUE);
			}
		}

		else if (snakeTrack == 18 || snakeTrack == 78) {

			x -= 100;
			y -= 50;

			setfillstyle(SOLID_FILL, YELLOW);
			circle(x, y, 6);
			floodfill(x, y, BLUE);
			setfillstyle(SOLID_FILL, MAGENTA);

			for (int i = 1; i < 6; i++) {

				circle(x, y + (12 * i), 6);
				floodfill(x, y + (12 * i), BLUE);
			}
		}

		else if (snakeTrack == 30 || snakeTrack == 90) {

			x -= 100;
			y -= 50;

			setfillstyle(SOLID_FILL, YELLOW);
			circle(x, y, 6);
			floodfill(x, y, BLUE);
			setfillstyle(SOLID_FILL, MAGENTA);

			for (int i = 1; i < 6; i++) {

				circle(x + (12 * i), y, 6);
				floodfill(x + (12 * i), y, BLUE);

			}
		}

		else if (snakeTrack == 39) {

			y -= 50;

			setfillstyle(SOLID_FILL, YELLOW);
			circle(x, y, 6);
			floodfill(x, y, BLUE);
			setfillstyle(SOLID_FILL, MAGENTA);

			for (int i = 1; i < 6; i++) {

				circle(x - (12 * i), y, 6);
				floodfill(x - (12 * i), y, BLUE);
			}
		}

		else if (snakeTrack == 48) {

			x += 100;
			y -= 50;

			setfillstyle(SOLID_FILL, YELLOW);
			circle(x, y, 6);
			floodfill(x, y, BLUE);
			setfillstyle(SOLID_FILL, MAGENTA);

			for (int i = 1; i < 6; i++) {

				circle(x, y + (12 * i), 6);
				floodfill(x, y + (12 * i), BLUE);
			}
		}

		else if (snakeTrack == 60) {

			x += 100;
			y -= 50;

			setfillstyle(SOLID_FILL, YELLOW);
			circle(x, y, 6);
			floodfill(x, y, BLUE);
			setfillstyle(SOLID_FILL, MAGENTA);

			for (int i = 1; i < 6; i++) {

				circle(x - (12 * i), y, 6);
				floodfill(x - (12 * i), y, BLUE);

			}
		}

		else if ((snakeTrack < 9) || (snakeTrack > 20 && snakeTrack < 30) || (snakeTrack > 41 && snakeTrack < 48) || (snakeTrack > 60 && snakeTrack < 69) || (snakeTrack > 80 && snakeTrack < 90)) {

			x += 150;

			setfillstyle(SOLID_FILL, YELLOW);
			circle(x, y, 6);
			floodfill(x, y, BLUE);
			setfillstyle(SOLID_FILL, MAGENTA);

			for (int i = 1; i < 6; i++) {

				circle(x - (12 * i), y, 6);
				floodfill(x - (12 * i), y, BLUE);
			}

		}

		else if ((snakeTrack > 11 && snakeTrack < 18) || (snakeTrack > 30 && snakeTrack < 39) || (snakeTrack > 50 && snakeTrack < 60) || (snakeTrack > 71 && snakeTrack < 78) || (snakeTrack > 90 && snakeTrack < 99)) {

			x -= 150;

			setfillstyle(SOLID_FILL, YELLOW);
			circle(x, y, 6);
			floodfill(x, y, BLUE);
			setfillstyle(SOLID_FILL, MAGENTA);

			for (int i = 1; i < 6; i++) {

				circle(x + (12 * i), y, 6);
				floodfill(x + (12 * i), y, BLUE);
			}

		}

		snakeTrack += 3;

	}


};


#endif // SNAKE_H
