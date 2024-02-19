#include"Game.h"
#include"GameObject.h"
#include"Player.h"
#include"Dice.h"
#include"Snake.h"

#ifndef MEDIUM_H
#define MEDIUM_H

using namespace std;

class Medium : public SinglePlayer {

public:

	void drawPictures() {

		readimagefile("Wall.jpg", 102, 450, 55, 497);
		readimagefile("Wall.jpg", 402, 300, 355, 347);
		readimagefile("Wall.jpg", 202, 100, 155, 147);
		readimagefile("Dice.jpg", 252, 350, 205, 397);
		readimagefile("Dice.jpg", 152, 250, 105, 297);
		readimagefile("Spikes.jpg", 452, 150, 405, 197);
		readimagefile("Heart.jpg", 552, 400, 505, 447);
		readimagefile("ArrowLeft.jpg", 352, 50, 305, 97);
		readimagefile("Flag.jpg", 102, 50, 55, 97);

		setcolor(BLACK);
		settextstyle(3, HORIZ_DIR, 2);
		setbkcolor(3);
		outtextxy(100, 600, "LIVES: ");

		settextstyle(BOLD_FONT, HORIZ_DIR, 4);
		setcolor(BLACK);
		setbkcolor(CYAN);
		outtextxy(655, 50, "GAME MODE");
		outtextxy(920, 50, "LEVEL");

		setfillstyle(SOLID_FILL, DARKGRAY);
		setcolor(LIGHTGRAY);
		rectangle(655, 85, 828, 140);
		rectangle(900, 85, 1040, 140);

		floodfill(657, 87, LIGHTGRAY);
		floodfill(902, 87, LIGHTGRAY);

		setcolor(BLACK);
		rectangle(670, 95, 810, 129);
		rectangle(915, 95, 1025, 129);

		setfillstyle(SOLID_FILL, BLACK);
		floodfill(672, 97, BLACK);
		floodfill(917, 97, BLACK);


		setcolor(WHITE);
		setbkcolor(BLACK);
		settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
		outtextxy(695, 103, "SINGLE");
		outtextxy(928, 103, "MEDIUM");
		
			setcolor(BLACK);
		setfillstyle(SOLID_FILL, LIGHTBLUE);
		rectangle(620,430,1050,473);
		line(810,460,1030,460);
		floodfill(631, 432, BLACK);
		
		setcolor(BLACK);
		setbkcolor(LIGHTBLUE);
		settextstyle(GOTHIC_FONT, HORIZ_DIR, 1);
		outtextxy(630,441, "Player Name:");
		outtextxy(816,440, playername);
		
		ifstream fin;
		char highScore[50];

		fin.open("MediumScores.txt");
		fin.getline(highScore, 50);
		setcolor(RED);
		setfillstyle(SOLID_FILL, RED);
		rectangle(640,504,1040,550);
		floodfill(641,505,RED);
		
		setcolor(3);
		setfillstyle(SOLID_FILL, CYAN);
		rectangle(649,512,1031,543);
		floodfill(653,519,CYAN);
		
		rectangle(662,502,1018,555);
		floodfill(663,505,CYAN);
		floodfill(816,549,CYAN);
		
		setcolor(BLACK);
		setbkcolor(3);
		settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
		outtextxy(656,518,highScore);
		fin.close();


	}

	int rollDice() {

		srand(time(NULL));
		static int callcount = 0;

		if (callcount == 4)
			callcount = 0;

		if (callcount > 0 && callcount < 4) {
			callcount++;
			return (rand() % 3) + 1;

		}

		else if (player1->playerTrack == 37) {
			PlaySound(TEXT("Moves.wav"), NULL, SND_FILENAME | SND_NODEFAULT | SND_ASYNC);
			callcount++;
			return (rand() % 3) + 1;
		}

		else if (player1->playerTrack == 59) {
			PlaySound(TEXT("Moves.wav"), NULL, SND_FILENAME | SND_NODEFAULT | SND_ASYNC);
			callcount++;
			return (rand() % 3) + 1;
		}

		else
			return (rand() % 6) + 1;

	}

	int movePlayer(int diceResult) {

		cout << "Track: " << player1->playerTrack << endl;
		cout << "Snake Track: " << snake.snakeTrack << endl << endl;

		if (player1->playerTrack == 20 || player1->playerTrack == 47 || player1->playerTrack == 83) {
			PlaySound(TEXT("WallSound.wav"), NULL, SND_FILENAME | SND_NODEFAULT | SND_ASYNC);
		}

		if (player1->playerTrack == 97 && player1->speed == 1)
			PlaySound(TEXT("Fast.wav"), NULL, SND_FILENAME | SND_NODEFAULT | SND_ASYNC);

		if (player1->playerTrack == 30 && gameboard.respawn == 1)
			PlaySound(TEXT("Health.wav"), NULL, SND_FILENAME | SND_NODEFAULT | SND_ASYNC);

		if (player1->playerTrack == 73 && gameboard.respawn == 0)
			PlaySound(TEXT("Death.wav"), NULL, SND_FILENAME | SND_NODEFAULT | SND_ASYNC);


		if ((snake.snakeTrack >= player1->playerTrack || player1->playerTrack + diceResult == 73) && gameboard.respawn == 0) {

			return -1;
		}

		else if (player1->playerTrack + diceResult == 73 && gameboard.respawn == 1)
			gameboard.respawn = 0;

		else if (player1->playerTrack + diceResult >= 100)
			return -2;

		else if (player1->playerTrack < 20 && player1->playerTrack + diceResult >= 20) {
			player1->blocked = 1;
		}

		else if (player1->playerTrack < 47 && player1->playerTrack + diceResult >= 47)
			player1->blocked = 1;

		else if (player1->playerTrack < 83 && player1->playerTrack + diceResult >= 83)
			player1->blocked = 1;

		else if (player1->playerTrack + diceResult == 95) {

			player1->x -= 150;
			circle(player1->x, player1->y, 20);
			floodfill(player1->x, player1->y, RED);
			player1->speed = 1;
			player1->playerTrack = player1->playerTrack + 3;
		}

		else if (player1->playerTrack + diceResult == 30)	 //powerUp: Shield
			gameboard.respawn = 1;


		for (int i = 0; i < diceResult; i++) {
			cleardevice();
			gameboard.drawGameBoard();
			drawPictures();
			setcolor(RED);
			setfillstyle(SOLID_FILL, RED);
			number1(diceResult);
		}

		player1->blocked = 0;

	}

	void number1(int diceResult) {

		if (player1->playerTrack == 20 && player1->blocked == 1) {
			circle(player1->x, player1->y, 20);
			floodfill(player1->x, player1->y, RED);
		}

		else if (player1->playerTrack == 47 && player1->blocked == 1) {
			circle(player1->x, player1->y, 20);
			floodfill(player1->x, player1->y, RED);
		}

		else if (player1->playerTrack == 83 && player1->blocked == 1) {
			circle(player1->x, player1->y, 20);
			floodfill(player1->x, player1->y, RED);
		}

		else if (player1->playerTrack < 10) {
			player1->x += 50;
			circle(player1->x, player1->y, 20);
			floodfill(player1->x, player1->y, RED);
			player1->playerTrack = player1->playerTrack + 1;
		}
		else if ((player1->playerTrack == 10) || (player1->playerTrack == 30) || (player1->playerTrack == 50) || (player1->playerTrack == 70) || (player1->playerTrack == 90)) {

			player1->y -= 50;
			circle(player1->x, player1->y, 20);
			floodfill(player1->x, player1->y, RED);
			player1->playerTrack = player1->playerTrack + 1;
		}
		else if (player1->playerTrack < 20) {

			player1->x -= 50;
			circle(player1->x, player1->y, 20);
			floodfill(player1->x, player1->y, RED);
			player1->playerTrack = player1->playerTrack + 1;
		}
		else if ((player1->playerTrack == 20) || (player1->playerTrack == 40) || (player1->playerTrack == 60) || (player1->playerTrack == 80)) {

			player1->y -= 50;
			circle(player1->x, player1->y, 20);
			floodfill(player1->x, player1->y, RED);
			player1->playerTrack = player1->playerTrack + 1;

		}
		else if ((player1->playerTrack < 30) || (player1->playerTrack > 40 && player1->playerTrack < 50) || (player1->playerTrack > 60 && player1->playerTrack < 70) || (player1->playerTrack > 80 && player1->playerTrack < 90)) {

			player1->x += 50;
			circle(player1->x, player1->y, 20);
			floodfill(player1->x, player1->y, RED);
			player1->playerTrack = player1->playerTrack + 1;

		}
		else if ((player1->playerTrack < 40) || (player1->playerTrack > 50 && player1->playerTrack < 60) || (player1->playerTrack > 70 && player1->playerTrack < 80) || (player1->playerTrack > 90 && player1->playerTrack < 99)) {

			player1->x -= 50;
			circle(player1->x, player1->y, 20);
			floodfill(player1->x, player1->y, RED);
			player1->playerTrack = player1->playerTrack + 1;
		}

	}

	int takeTurn() {

		player1->movecount++;

		int num = rollDice();

		dice.draw(num);
		dice.drawRollRectanlge();

		int value = movePlayer(num);
		snake.moveSnake();

		if (snake.snakeTrack >= player1->playerTrack && gameboard.respawn == 1) {

			movePlayer(3);
			gameboard.respawn = 0;
			gameboard.drawGameBoard();
			drawPictures();
			dice.draw(num);
			snake.draw();
			player1->draw();
			dice.drawRollRectanlge();
		}

		else if (value == -1) {
			return -1;
		}								//did this cuz there was a bug in the previous logic
		else if (value == -2) {
			return -2;
		}

		dice.draw(num);
		dice.drawRollRectanlge();

	}

	void manageHS() {

		ofstream fout;
		ifstream fin;
		int currHS;
		char input[10];

		fin.open("MediumScores.txt");
		fin.seekg(11);
		fin.getline(input, 4);
		currHS = atoi(input);
		fin.close();

		if (player1->movecount < currHS) {
			fout.open("MediumScores.txt");
			fout << "Highscore: " << player1->movecount << " by " << player1->name;
		}
		fout.close();
	}


};

#endif // MEDIUM_H
