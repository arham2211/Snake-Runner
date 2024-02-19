#include"Game.h"
#include"GameObject.h"
#include"Player.h"
#include"Dice.h"
#include"Snake.h"

#ifndef SINGLE_PLAYER_H
#define SINGLE_PLAYER_H

class SinglePlayer : public Game {

public:
	
	
	virtual void manageHS() = 0;
	virtual int rollDice() = 0;
	virtual int movePlayer(int) = 0;
	virtual void number1(int) = 0;
	virtual int takeTurn() = 0;


};


#endif // SINGLE_PLAYER_H

