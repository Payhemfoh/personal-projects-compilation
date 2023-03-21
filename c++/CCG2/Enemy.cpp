#include "Enemy.h"
Enemy::Enemy(float x, float y, int hp, float speed) 
	:Character(x, y, hp, speed),hitbox(80)
{}

void Enemy::draw() {
	glPushMatrix();
	glLoadIdentity();
	glColor3f(0.7f, 0.7f, 0.7f);
	this->drawCircle(x, y, 70, 20, 0, 1, 1);

	glColor3f(0.4f, 0.4f, 0.4f);
	this->drawCircle(x-50, y, 10, 20, 0, 1, 1);
	this->drawCircle(x, y+40, 10, 20, 0, 1, 1);
	this->drawCircle(x-10, y-20, 10, 20, 0, 1, 1);
	this->drawCircle(x+40, y, 10, 20, 0, 1, 1);
	this->drawCircle(x, y-50, 10, 20, 0, 1, 1);

	glPopMatrix();
}

Bullet* Enemy::attack() {
	return new Bullet(this->x, this->y, 1, false);
}

void Enemy::attacked(Bullet& bullet) {
	//calculate shortest distance between bullet and draw point
	//then check for hitbox radius
	double distance = sqrt(pow((bullet.x - this->x),2)+pow((bullet.y - this->y),2));
	if (distance < hitbox) {
		bullet.hit = true;
		--hp;
	}
}