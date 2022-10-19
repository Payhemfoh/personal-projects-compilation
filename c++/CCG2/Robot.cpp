#include "Robot.h"

Robot::Robot(float x, float y, int hp, float speed) 
	:Character(x, y, hp, speed),hitbox(150)
{}

void Robot::draw() {
	glPushMatrix();
	glLoadIdentity();
	//scale down the drawing
	glTranslatef(x, y, 0);
	glScalef(0.5f, 0.5f, 1.0f);
	glTranslatef(-x, -y, 0);

	glColor3f(68 / 255.0f, 114 / 255.0f, 196 / 255.0f);
	this->drawQuad(x-215, y+150, x+215, y+150, x+215, y-150, x-215, y-150);

	glColor3f(200 / 255.0f, 114 / 255.0f, 196 / 255.0f);
	this->drawQuad(x-65, y+450, x+85, y+450, x+55, y+350, x-35, y+350);

	glColor3f(68 / 255.0f, 114 / 255.0f, 196 / 255.0f);
	this->drawCircle(x, y+150, 215, 50, 0, 1, 1);

	glColor3f(0.0f, 0.0f, 0.0f);
	this->drawQuad(x-165, y+250, x+165, y+250, x+165, y+50, x-165, y+50);
	
	glColor3f(1.0f, 1.0f, 1.0f);
	this->drawCircle(x-70, y+180, 50, 50, 0, 1, 1);
	this->drawCircle(x+80, y+180, 50, 50, 0, 1, 1);

	glColor3f(51 / 255.0f, 73 / 255.0f, 170 / 255.0f);
	this->drawTriangle(x-365, y-100, x-215, y+80, x-215, y-100);

	glColor3f(51 / 255.0f, 73 / 255.0f, 170 / 255.0f);
	this->drawTriangle(x+215, y-100, x+215, y+80, x+365, y-100);
	
	glLoadIdentity();
	glPopMatrix();
}

Bullet* Robot::attack() {
	return new Bullet(this->x, this->y, 20, true);
}

void Robot::attacked(Enemy& enemy) {
	//calculate shortest distance between bullet and draw point
	//then check for hitbox radius
	double distance = sqrt(pow((enemy.x - this->x), 2) + pow((enemy.y - this->y), 2));
	if (distance < hitbox) {
		this->hp -= enemy.hp;
		enemy.hp = 0;
	}
}
