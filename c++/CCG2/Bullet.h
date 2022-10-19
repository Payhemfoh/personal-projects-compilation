#ifndef _BULLET_H_
#define _BULLET_H_

#include "Object.h"

class Bullet : public Object
{
private:
	bool upDirection;
	float speed;
public:
	bool hit;
	Bullet(float x, float y, float speed, bool upDirection);
	void draw();
	void move();
};

#endif