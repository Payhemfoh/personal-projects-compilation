#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include <iostream>
#include "Bullet.h"
#include "Object.h"
#include <GL/glut.h>

using namespace std;

class Character : public Object{
public:
	int hp;
	float speed;
public:
	Character(float x, float y, int hp, float speed);
	~Character();

	virtual void draw() = 0;
	bool isAlive();
	void move(int direction);
	void move(float x,float y);
	virtual Bullet* attack() = 0;
};

#endif
