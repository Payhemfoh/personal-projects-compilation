#ifndef _ROBOT_H_
#define _ROBOT_H_

#include <cmath>
#include "character.h"
#include "Enemy.h"

class Robot:public Character
{
private:
	double hitbox;
public:
	Robot(float x, float y, int hp, float speed);
	void draw();
	Bullet* attack();
	void attacked(Enemy& enemy);
};

#endif
