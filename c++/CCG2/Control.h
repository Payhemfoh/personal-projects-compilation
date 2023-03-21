#ifndef _CONTROL_H_
#define _CONTROL_H_

/*
	This class is used to record the user input and to be used in the manipulation of game logic
*/
class Control
{
public:
	Control();
	double mousePosX, mousePosY;
	double diffPosX, diffPosY;
	bool leftMouseIsPressed, rightMouseIsPressed;
	int keyPressed;
	bool keyboardAction;
};

#endif