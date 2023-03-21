#ifndef _GAMEENGINE_H_
#define _GAMEENGINE_H_

#include "Control.h"
#include "Enemy.h"
#include "Robot.h"
#include "Bullet.h"

/*
	This class will record the game status and handle the game logic of the program
*/	
class GameEngine
{
private:
	double score;
	bool gameStatus;
	Robot main_robot;
	Enemy* enemies[10];
	Bullet* bullets[50];
	int num_enemies;
	int num_bullet;
	int enemy_waves;
public:
	//default constructor which set the score to 0 and gameStatus to true
	GameEngine();

	~GameEngine();

	//start the game and loop the game logic process until the gameStatus is false (Game Over)
	void StartGame();

	/*
	perform the game logic process which including movement, attack, enemy spawn, score calculation
	*/
	void HandleGameEvent();
	
	/*
	this method is used to handle the user input from either keyboard or mouse
	this method should be called from the keyboardfunc, mousefunc of glut to direct manipulate game status
	@param control - The class to record the user input
	*/
	void HandleUserInput(Control control);

	/*
	add the score to current score, to be used in the game when enemy is eliminated
	@param score the score to be added
	*/
	void CalculateScore(double score);

	//reset the game status to true and score to 0 which should be called before restart a new game
	void ResetStatus();

	//get the current score in the game;
	double getScore();

	//render the game screen which contains enemy and main character.
	void RenderGameScreen();

	//generate enemy if all the enemy are eliminated (only for fixed times)
	void GenerateEnemy();

	void ManageBullets();

	void EndGame();

	void ManageEnemies();

	bool getGameStatus();

	Robot getRobot();
};
#endif
