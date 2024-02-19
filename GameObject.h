
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

class GameObject {



public:

	int x;
	int y;

	GameObject(int x, int y) :x(x), y(y) {}

	virtual void draw() = 0;

};


#endif // GAME_OBJECT_H
