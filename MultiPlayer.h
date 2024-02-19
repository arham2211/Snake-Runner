#include"Game.h"
#include"GameObject.h"
#include"Player.h"
#include"Dice.h"
#include"Snake.h"

#ifndef MULTI_PLAYER_H
#define MULTI_PLAYER_H

using namespace std;

class MultiPlayer :public Game {

public:

	void drawTurn(int player) {

		if (player == 1) {

			setfillstyle(SOLID_FILL, LIGHTRED);
			setcolor(LIGHTRED);
			rectangle(400, 590, 590, 630);
			floodfill(402, 592, LIGHTRED);


			settextstyle(8, HORIZ_DIR, 1);
			setbkcolor(LIGHTRED);
			setcolor(BLACK);
			outtextxy(411, 600, "Player 1's turn");

		}
		else if (player == 2) {

			setfillstyle(SOLID_FILL, LIGHTBLUE);
			setcolor(LIGHTBLUE);
			rectangle(400, 590, 590, 630);
			floodfill(402, 592, LIGHTBLUE);


			settextstyle(8, HORIZ_DIR, 1);
			setbkcolor(LIGHTBLUE);
			setcolor(BLACK);
			outtextxy(411, 600, "Player 2's turn");

		}
	}

	void drawFirstWindow() {

		player1->x = 126;
		player2->x = 126;

		player1->playerTrack = 1;
		player2->playerTrack = 1;

		gameboard.drawGameBoard();
		dice.draw(1);
		dice.drawRollRectanlge();

		drawTurn(1);
		player2->draw(1);
		player1->draw(4);

	}

	void drawPictures() {

		readimagefile("Spikes.jpg", 302, 450, 255, 497);
		readimagefile("Wall.jpg", 402, 400, 355, 447);
		readimagefile("Dice.jpg", 202, 350, 155, 397);
		readimagefile("Heart.jpg", 352, 250, 305, 297);
		readimagefile("Wall.jpg", 102, 250, 55, 297);
		readimagefile("Spikes.jpg", 502, 200, 555, 247);
		readimagefile("Dice.jpg", 302, 150, 255, 197);
		readimagefile("Wall.jpg", 152, 100, 105, 147);
		readimagefile("ArrowLeft.jpg", 452, 50, 405, 97);
		readimagefile("Flag.jpg", 102, 50, 55, 97);


		setfillstyle(SOLID_FILL, DARKGRAY);
		setcolor(LIGHTGRAY);
		rectangle(755, 85, 998, 140);

		floodfill(757, 87, LIGHTGRAY);

		setcolor(BLACK);
		rectangle(770, 95, 980, 129);

		setfillstyle(SOLID_FILL, BLACK);
		floodfill(772, 97, BLACK);

		setcolor(BLACK);
		setbkcolor(CYAN);
		settextstyle(BOLD_FONT, HORIZ_DIR, 4);
		outtextxy(795, 50, "GAME MODE");

		setcolor(WHITE);
		setbkcolor(BLACK);
		settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
		outtextxy(795, 103, "Multiplayer");

		settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
		outtextxy(30, 600, "PLAYER 1 LIVES:");

		settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
		outtextxy(30, 650, "PLAYER 2 LIVES:");


	}

	int rollDice(Player* player) {

		srand(time(0));

		if (player->limitedroll == 4)
			player->limitedroll = 0;

		if (player->limitedroll > 0 && player->limitedroll < 4) {
			player->limitedroll++;
			return (rand() % 3) + 1;

		}

		else if (player->playerTrack == 38) {
			PlaySound(TEXT("Moves.wav"), NULL, SND_FILENAME | SND_NODEFAULT | SND_ASYNC);
			player->limitedroll++;
			return (rand() % 3) + 1;
		}

		else if (player->playerTrack == 76) {
			PlaySound(TEXT("Moves.wav"), NULL, SND_FILENAME | SND_NODEFAULT | SND_ASYNC);
			player->limitedroll++;
			return (rand() % 3) + 1;
		}

		else
			return (rand() % 6) + 1;
	}

	int movePlayer(int diceResult, Player* player, int color) {

		//cout << "Track: " << player->playerTrack << endl;
	
		if (player->playerTrack== 27 || player->playerTrack == 60 || player->playerTrack == 82) 
		PlaySound(TEXT("WallSound.wav"), NULL, SND_FILENAME | SND_NODEFAULT | SND_ASYNC);
		

		if (player->playerTrack == 55 && gameboard.respawn == 1)
			PlaySound(TEXT("Health.wav"), NULL, SND_FILENAME | SND_NODEFAULT | SND_ASYNC);

		if ((player->playerTrack == 16 || player->playerTrack == 69) && gameboard.respawn == 0)
			PlaySound(TEXT("Death.wav"), NULL, SND_FILENAME | SND_NODEFAULT | SND_ASYNC);

		if (player->playerTrack == 96 && player->speed == 1)
			PlaySound(TEXT("Fast.wav"), NULL, SND_FILENAME | SND_NODEFAULT | SND_ASYNC);
		
		if (player->playerTrack + diceResult == 69 && gameboard.respawn == 0 && color ==4) {

			return -1;
		}
		
		else if (player->playerTrack + diceResult == 69 && gameboard.respawn2 == 0 && color ==1) {

			return -1;
		}
		
		else if (player->playerTrack + diceResult == 16) {
			return -2;
		}

		else if (player->playerTrack + diceResult >= 100) {
			return -1;
		}

		else if (player->playerTrack + diceResult == 69 && gameboard.respawn == 1 && color == 4)
			gameboard.respawn = 0;

		else if (player->playerTrack + diceResult == 69 && gameboard.respawn2 == 1 && color == 1)
			gameboard.respawn2 = 0;

		else if (player->playerTrack < 27 && player->playerTrack + diceResult >= 27) {
			player->blocked = 1;
		}

		else if (player->playerTrack < 60 && player->playerTrack + diceResult >= 60)
			player->blocked = 1;

		else if (player->playerTrack < 82 && player->playerTrack + diceResult >= 82)
			player->blocked = 1;

		else if (player->playerTrack + diceResult == 93) {

			setcolor(color);
			player->x -= 150;
			circle(player->x, player->y, 20);
			floodfill(player->x, player->y, color);
			player->speed = 1;
			player->playerTrack = player->playerTrack + 3;
		}

		else if (player->playerTrack + diceResult == 55) {

			if (color == 1) {
				gameboard.respawn2 = 1;
				gameboard.drawGameBoard();
			}
			if (color == 4) {
				gameboard.respawn = 1;
				gameboard.drawGameBoard();
			}
		}

		for (int i = 0; i < diceResult; i++) {
			cleardevice();
			gameboard.drawGameBoard();
			drawPictures();
			setcolor(color);
			setfillstyle(SOLID_FILL, color);
			number1(diceResult, player, color);
		}

		player->blocked = 0;

	}

	void number1(int diceResult, Player* player, int color) {

		if (player->playerTrack == 27 && player->blocked == 1) {
			circle(player->x, player->y, 20);
			floodfill(player->x, player->y, color);
		}

		else if (player->playerTrack == 60 && player->blocked == 1) {
			circle(player->x, player->y, 20);
			floodfill(player->x, player->y, color);
		}

		else if (player->playerTrack == 82 && player->blocked == 1) {
			circle(player->x, player->y, 20);
			floodfill(player->x, player->y, color);
		}

		else if (player->playerTrack < 10) {
			player->x += 50;
			circle(player->x, player->y, 20);
			floodfill(player->x, player->y, color);
			player->playerTrack = player->playerTrack + 1;
		}
		else if ((player->playerTrack == 10) || (player->playerTrack == 30) || (player->playerTrack == 50) || (player->playerTrack == 70) || (player->playerTrack == 90)) {

			player->y -= 50;
			circle(player->x, player->y, 20);
			floodfill(player->x, player->y, color);
			player->playerTrack = player->playerTrack + 1;
		}
		else if (player->playerTrack < 20) {

			player->x -= 50;
			circle(player->x, player->y, 20);
			floodfill(player->x, player->y, color);
			player->playerTrack = player->playerTrack + 1;
		}
		else if ((player->playerTrack == 20) || (player->playerTrack == 40) || (player->playerTrack == 60) || (player->playerTrack == 80)) {

			player->y -= 50;
			circle(player->x, player->y, 20);
			floodfill(player->x, player->y, color);
			player->playerTrack = player->playerTrack + 1;

		}
		else if ((player->playerTrack < 30) || (player->playerTrack > 40 && player->playerTrack < 50) || (player->playerTrack > 60 && player->playerTrack < 70) || (player->playerTrack > 80 && player->playerTrack < 90)) {

			player->x += 50;
			circle(player->x, player->y, 20);
			floodfill(player->x, player->y, color);
			player->playerTrack = player->playerTrack + 1;

		}
		else if ((player->playerTrack < 40) || (player->playerTrack > 50 && player->playerTrack < 60) || (player->playerTrack > 70 && player->playerTrack < 80) || (player->playerTrack > 90 && player->playerTrack < 99)) {

			player->x -= 50;
			circle(player->x, player->y, 20);
			floodfill(player->x, player->y, color);
			player->playerTrack = player->playerTrack + 1;
		}

	}

	int takeTurn(Player* player, int color) {

		player->movecount++;
	
		int num = rollDice(player);
	
			
		dice.draw(num);
		dice.drawRollRectanlge();

		int value = movePlayer(num, player, color);
			cout<<"Track:"<<player->playerTrack<<"Color: "<<color<<endl;
		

		if (value == -1) {
			return -1;
		}
		else if (value == -2) {
			return -2;
		}

		dice.draw(num);
		dice.drawRollRectanlge();

	}

	void youWin(int playernum) {


	int j, x = 320, y = 240, r = 100;

	 setbkcolor(BLACK);
    cleardevice();
    
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


    settextstyle(BOLD_FONT, HORIZ_DIR, 6);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    setcolor(WHITE);
    
    		if (playernum == 1)
			outtextxy(getmaxx() / 2, getmaxy() / 2, "Player 1 Wins!");
		else if (playernum == 2)
			outtextxy(getmaxx() / 2, getmaxy() / 2, "Player 2 Wins!");

	}


};


#endif // MULTI_PLAYER_H

