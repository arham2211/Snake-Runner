#include"GameBoard.h"
#include"GameObject.h"
#include"Player.h"
#include"Dice.h"
#include"Snake.h"

#ifndef GAME_H
#define GAME_H

using namespace std;

class Game {

protected:

	GameBoard gameboard;
	Snake snake;
	Dice dice;

public:

	Player* player2;
	Player* player1;
	Game() {

		player1 = new Player;
		player2 = new Player;
	}

	virtual void drawPictures() = 0;

	void drawFirstWindow() {

		gameboard.drawGameBoard();
		dice.draw(1);
		snake.draw();
		dice.drawRollRectanlge();
		player1->draw();

	}

	void gameOver() {

		cleardevice();
		setbkcolor(BLACK);
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(20, 20, LIGHTRED);
		setcolor(LIGHTRED);
		settextstyle(3, HORIZ_DIR, 10);
		outtextxy(140, 200, "GAME OVER");
	}

	void youWin() {
		
		int j, x = 320, y = 240, r = 100;

		 setbkcolor(BLACK);
    cleardevice();


    // Draw stars
    for (int i = 0; i < 50; i++) {
        int x_star = rand() % getmaxx();
        int y_star = rand() % getmaxy();
        setcolor(WHITE);
        for (j = 0; j < 5; j++) {
            int x1 = x_star + 5 * cos(j * 72 * 3.14 / 180);
            int y1 = y_star + 5 * sin(j * 72 * 3.14 / 180);
            int x2 = x_star + 10 * cos((j + 2) * 72 * 3.14 / 180);
            int y2 = y_star + 10 * sin((j + 2) * 72 * 3.14 / 180);
            line(x1, y1, x2, y2);
        }
    }

    // Draw text
    settextstyle(BOLD_FONT, HORIZ_DIR, 6);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    setcolor(WHITE);
    outtextxy(getmaxx() / 2, getmaxy() / 2, "Congratulations! You Win!");
		
	}
};

#endif // GAME_H
