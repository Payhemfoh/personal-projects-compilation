#include "Bullet.h"

Bullet::Bullet(float x, float y, float speed, bool upDirection) 
	:speed(speed),upDirection(upDirection),hit(false)
{
	this->x = x;
	this->y = y;
}

void Bullet::draw() {
	glPushMatrix();
	glColor3f(0.0f, 1.0f, 0.0f);
	drawCircle(x, y, 15, 20, 0, 1, 1);
	glPopMatrix();
}

void Bullet::move() {
	if (upDirection) {
		this->y += speed;
	}
	else {
		this->y -= speed;
	}
}