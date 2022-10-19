#include "Object.h"
#include"character.h"

Character::Character(float x,float y, int hp,float speed)
	:hp(hp),speed(speed)
{
	this->x = x;
	this->y = y;
}

Character::~Character(){}

bool Character::isAlive() {
	return hp > 0;
}

void Character::move(int direction) {
	switch (direction) {
	case 1:
		if (this->y + speed <= 1900) {
			this->y += speed;
		}
		break;
	case 2:
		if (this->y - speed >= 0) {
			this->y -= speed;
		}
		break;
	case 3:
		if (this->x - speed >= 0) {
			this->x -= speed;
		}
		break;
	case 4:
		if (this->x + speed <= 1600) {
			this->x += speed;
		}
		break;
	}
}

void Character::move(float x, float y) {
	//this should be canvas size
	if (this->x + x >= 0 && this->x + x <= 1600) {
		this->x += x;
	}

	if (this->y + y >= 0 && this->y + y <= 1900) {
		this->y += y;
	}
}
