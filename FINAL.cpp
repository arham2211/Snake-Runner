#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <Windows.h>
#include<mmsystem.h>
#include <fstream>

// HEADER FILES

#include"GameBoard.h"
#include"GameObject.h"
#include"Player.h"
#include"Dice.h"
#include"Snake.h"
#include"Game.h"
#include"SinglePlayer.h"
#include"Easy.h"
#include"Medium.h"
#include"Hard.h"
#include"MultiPlayer.h"

using namespace std;

void drawMenu() {


	setbkcolor(BLACK);
	cleardevice();

	readimagefile("Menu.jpg", 0, 0, 1100, 700);



}

void instructionPage() {

	setbkcolor(CYAN);
	cleardevice();
	setcolor(WHITE);
	settextstyle(BOLD_FONT, HORIZ_DIR, 3);

	readimagefile("Wall.jpg", 170, 250, 126, 297);
	readimagefile("Dice.jpg", 170, 307, 126, 354);
	readimagefile("Spikes.jpg", 170, 364, 126, 411);
	readimagefile("Heart.jpg", 170, 480, 126, 527);
	readimagefile("ArrowRight.jpg", 170, 537, 126, 584);
	readimagefile("Freeze.jpg", 170, 594, 126, 641);

	outtextxy(260, 80, "Roll For Survival Game Instructions");

	outtextxy(170, 170, "1. Roll the dice to survive from the snake.");

	outtextxy(170, 210, "OBSTACLES:");
	outtextxy(235, 265, "--> Blocks the player turn");
	outtextxy(235, 320, "--> Randomly generates number till 3");
	outtextxy(235, 375, "--> Immediate death");

	outtextxy(170, 440, "POWER-UPS:");
	outtextxy(235, 493, "--> Gives you a life");
	outtextxy(235, 548, "--> Dice makes player forward");
	outtextxy(235, 603, "--> Freezes the snake");

	rectangle(150, 50, 900, 650);
	rectangle(151, 49, 901, 649);

	rectangle(725, 570, 870, 620);
	outtextxy(768, 585, "BACK");

}


int main() {

	int endthegame=0;
	int gdriver = DETECT, gmode;
	initwindow(1100, 700, "Snake Game Board");

	int x, y;
	int page = 1;

	bool playClicked = false;

	SinglePlayer* singlePlayer = NULL;
	MultiPlayer multiplayer;

back:

	drawMenu();

	while (!playClicked) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if (x >= 455 && x <= 655 && y >= 245 && y <= 295) {
				int mode = difficultyPage();
				if (mode == 0) {

					singlePlayer = new Easy;


				}
				else if (mode == 1) {

					singlePlayer = new Medium;
				}

				else if (mode == 2) {

					singlePlayer = new Hard;

				}

				singlePlayer->drawFirstWindow();
				singlePlayer->drawPictures();

				while (1) {
				

					if (ismouseclick(WM_LBUTTONDOWN)) {
						getmouseclick(WM_LBUTTONDOWN, x, y);
						if (x >= 802 && x <= 917 && y >= 333 && y <= 382) {

							setactivepage(page);
							setvisualpage(1 - page);
							
							if (endthegame==1)
								break;


							PlaySound(TEXT("dice.wav"), NULL, SND_FILENAME | SND_NODEFAULT | SND_ASYNC);
							int returnval = singlePlayer->takeTurn();


							if (returnval == -1) {
								singlePlayer->gameOver();
								endthegame=1;
							}

							else if (returnval == -2) {
								singlePlayer->youWin();
								singlePlayer->manageHS();
								endthegame=1;
							
							}

							page = 1 - page;

						}
						else if (x >= 920 && x <= 1020 && y >= 630 && y <= 670) {
							exit(0);
						}
					}
				}
				
				playClicked = true;
			}

			else if (x >= 455 && x <= 655 && y >= 322 && y <= 374) {

				multiplayer.drawFirstWindow();
				multiplayer.drawPictures();
				int turn = 0;

				while (1) {
					if (ismouseclick(WM_LBUTTONDOWN)) {
						getmouseclick(WM_LBUTTONDOWN, x, y);
						if (x >= 802 && x <= 917 && y >= 333 && y <= 382) {

							setactivepage(page);
							setvisualpage(1 - page);
							
							if(endthegame==1)
								break;

							if (turn == 0) {
								
								PlaySound(TEXT("dice.wav"), NULL, SND_FILENAME | SND_NODEFAULT | SND_ASYNC);
								int returnval = multiplayer.takeTurn(multiplayer.player1, 4);
								multiplayer.drawTurn(2);
								multiplayer.player2->draw(1);

								if (returnval == -1){
									
									multiplayer.youWin(1);
									endthegame=1;
								
								}
								else if (returnval == -2){
									multiplayer.youWin(2);
									endthegame=1;
								}
							

								turn = !turn;
							}

							else if (turn == 1) {
								
								PlaySound(TEXT("dice.wav"), NULL, SND_FILENAME | SND_NODEFAULT | SND_ASYNC);
								int returnval = multiplayer.takeTurn(multiplayer.player2, 1);
								multiplayer.drawTurn(1);
								multiplayer.player1->draw(4);

								if (returnval == -1){
									multiplayer.youWin(2);
									endthegame=1;
							
								}
								else if (returnval == -2){
									
									multiplayer.youWin(1);
									endthegame=1;
								
								}

								turn = !turn;
							}
							page = 1 - page;

						}

						else if (x >= 920 && x <= 1020 && y >= 630 && y <= 670) {
							exit(0);
						}
					}
				}
				
				
				playClicked = true;
			}

			else if (x >= 455 && x <= 655 && y >= 405 && y <= 457) {

				instructionPage();
				while (1) {

					if (ismouseclick(WM_LBUTTONDOWN)) {
						getmouseclick(WM_LBUTTONDOWN, x, y);
						if (x >= 725 && x <= 870 && y >= 570 && y <= 620)
							goto back;

					}
				}
			}
		}
	}



//	getch();
	//closegraph();
	
	delay(2000);


	return 0;
}

