#include "GameEngine.h"
#include <iostream>
#include <gl/glut.h>

GameEngine::GameEngine()
	:score(0.0), gameStatus(false),main_robot(200,950,10,25),num_enemies(0),num_bullet(0),enemy_waves(3)
{}

GameEngine::~GameEngine() {
	if (num_enemies != 0) {
		for (int i = 0; i < num_enemies; ++i)
			delete enemies[i];
	}

	if (num_bullet != 0) {
		for (int i = 0; i < num_bullet; ++i) {
			delete bullets[i];
		}
	}
}

void GameEngine::EndGame() {
	this->gameStatus = false;
}

void GameEngine::StartGame() {
	this->gameStatus = true;
}

bool GameEngine::getGameStatus() {
	return this->gameStatus;
}

Robot GameEngine::getRobot() {
	return this->main_robot;
}

void GameEngine::HandleGameEvent() {
	//check if enemy is attacked
	for (int i = 0; i < num_enemies; ++i) {
		for (int j = 0; j < num_bullet; ++j) {
			enemies[i]->attacked(*bullets[j]);
		}
	}

	ManageEnemies();

	//check if robot is attacked
	for (int i = 0; i < num_enemies; ++i) {
		main_robot.attacked(*enemies[i]);
	}
	

	if (!main_robot.isAlive()) {
		cerr << main_robot.hp << ' ' << main_robot.isAlive() << endl;
		EndGame();
	}

	ManageBullets();
}

void GameEngine::ManageEnemies() {
	//check if still alive
	//if no longer alive, delete the enemy and move all the enemy from back to enforce integrity
	//if still alive, then move downward
	Enemy* temp_enemies[10];
	int counter = 0;
	for (int i = 0; i < num_enemies; ++i) {
		if (enemies[i] && enemies[i]->isAlive()) {
			temp_enemies[counter++] = enemies[i];
		}
		else {
			if (enemies[i] && enemies[i]->y < 0) {
				delete enemies[i];
			}
			else if (enemies[i]) {
				delete enemies[i];
				CalculateScore(10);
			}
			enemies[i] = NULL;
		}
	}

	for (int i = 0; i < counter; ++i) {
		enemies[i] = temp_enemies[i];
		enemies[i]->move(2);
	}	
	num_enemies = counter;

	if (num_enemies == 0 && enemy_waves != 0) {
		GenerateEnemy();
	}
	else {
		EndGame();
	}
}

void GameEngine::ManageBullets() {
	//check if bullet is out of range
	//if out of range then delete the bullet
	//then move the bullet
	int counter = 0;
	Bullet* temp_bullets[50];

	for (int i = 0; i < num_bullet; ++i) {
		bullets[i]->move();
	}

	for (int i = 0; i < num_bullet; ++i) {
		if (!bullets[i]->hit &&
			(bullets[i]->x >= 0 && bullets[i]->x < 1600) &&
			(bullets[i]->y >= 0 && bullets[i]->y < 1900)) {
			temp_bullets[counter++] = bullets[i];
		}
		else {
			if(bullets[i])
				delete bullets[i];
			
			bullets[i] = NULL;
		}
	}

	for (int i = 0; i < counter; ++i) {
		bullets[i] = temp_bullets[i];
	}

	num_bullet = counter;
}

void GameEngine::CalculateScore(double score) {
	this->score += score;
}

void GameEngine::HandleUserInput(Control control) {
	//check is keyboard input or mouse input
	if (control.keyboardAction) {
		//keyboard input
		switch (control.keyPressed) {
		case (int)'w':
			main_robot.move(1);
			break;
		case (int)'s':
			main_robot.move(2);
			break;
		case (int)'a':
			main_robot.move(3);
			break;
		case (int)'d':
			main_robot.move(4);
			break;
		case (int)'q':
			if (num_bullet < 50)
				bullets[num_bullet++] = main_robot.attack();
			break;
		}
	}
	else {
		//mouse input
		if (control.leftMouseIsPressed || control.rightMouseIsPressed) {
			if (control.diffPosX != 0 || control.diffPosY != 0) {
				main_robot.move(control.diffPosX, control.diffPosY);
			}
			
			if(num_bullet < 50)
				bullets[num_bullet++] = main_robot.attack();
		}
	}
}

void GameEngine::ResetStatus() {
	this->score = 0.0;
	this->gameStatus = true;
}

double GameEngine::getScore() {
	return this->score;
}

void GameEngine::RenderGameScreen() {
	for (int i = 0; i < num_enemies; ++i) {
		enemies[i]->draw();
	}

   	main_robot.draw();

	for (int i = 0; i < num_bullet; ++i) {
		bullets[i]->draw();
	}
}

void GameEngine::GenerateEnemy() {
	for (int i = 0; i < 10; ++i) {
		enemies[i] = new Enemy(rand()%1600, 1600 + (rand()%300), 3, 1);
		++num_enemies;
	}
	--enemy_waves;
}