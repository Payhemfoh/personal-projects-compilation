#include <windows.h>
#include <gl/glut.h>
#include "Object.h"
#include "character.h"
#include "GameEngine.h"
#include "Control.h"
#include <string>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cmath>

using namespace std;

// for menu display
GLfloat angle = 0.0;
GLfloat angle2 = 0.0;
GLfloat xRotated, yRotated, zRotated;
GLdouble radius = 3;

void init()
{
//	glClearColor(23.0f/255.0f, 52.0f/255.0f, 68.0f/255.0f, 1.0f);//set bg color with rgba

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2,2,-2,2,-2,2);
    glMatrixMode(GL_MODELVIEW);
}

/*
	Used to store the window setting for this program
*/
struct Window {
	int width, height;
	int posX, posY;
	float r, g, b, a;
	char title[20];
	double canvasRatio;
} window = { 
	800,950,	//width,height
	500,50,		//posX,posY
	23.0f / 255.0f,	//r
	52.0f / 255.0f,	//g
	68.0f / 255.0f,	//b
	1.0f,			//a
	"Assign 2",		//title
	2.0				//canvas ratio
};

Control control;
GameEngine* game = NULL;
Object planet = Object();
Object star = Object();
Object text = Object();
string textPoints;
int score = 0;

/*
	Render the background of the program
*/
void renderBackground();

/*
	Perform action when user click mouse
*/
void mouseControl(GLint button, GLint status, int x, int y);

/*
	Perform action when user move the mouse
*/
void mouseMoveControl(GLint x, GLint y);

/*
	Perform action when user press keyboard
*/
void keyboardControl(unsigned char key, GLint x, GLint y);

/*
	Perform action when user press keyboard(arrow key edition)
*/
void keyboardControl2(int key, GLint x, GLint y);

/*
	Render function which will be looped to render the graphic
*/
void render();

void timer( int value )
{
    if( zRotated > 360.0 )
    {
        zRotated -= 360.0 * floor( zRotated / 360.0 ); // Don't allow overflow
    }

    if( yRotated > 360.0 )
    {
        yRotated -= 360.0 * floor( yRotated / 360.0 ); // Don't allow overflow
    }

    zRotated += 5.0;
    yRotated += 1.0;

    glutTimerFunc( 16, timer, 0 );
    glutPostRedisplay();
}

void menuDisplay()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    
	glColor3f(0.8, 0.7, 0.9);
	
    glDepthMask( GL_FALSE );
    glDisable( GL_DEPTH_TEST );
    glDisable( GL_LIGHTING );

    // 2D rendering
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( 0, 640, 0, 480, -1, 1 );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    glPushMatrix();
    {
        glColor3f( 1.0, 1.0, 1.0 );
        glPointSize( 3 );
        glBegin( GL_POINTS );
        for( int i = 1; i < 100; i++ )
        {
            int x = rand() % 640;
            int y = rand() % 480;
            glVertex2i( x, y );
        }
        glEnd();
    }
    glPopMatrix();


    glDepthMask( GL_TRUE );
    glEnable( GL_DEPTH_TEST );

    // Enable lighting
    glEnable( GL_LIGHTING );
    glEnable( GL_LIGHT0 );
    GLfloat qaSpecularLight[] = {1.0, 1.0, 1.0, 1.0};
    glLightfv( GL_LIGHT0, GL_SPECULAR, qaSpecularLight );

    // 3D rendering
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    double w = glutGet( GLUT_WINDOW_WIDTH );
    double h = glutGet( GLUT_WINDOW_HEIGHT );
    gluPerspective( 20.0, w / h, 0.1, 80.0 );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glTranslatef( 0.0, 0.0, -40.0 );

    glPushMatrix();
    {
        glutSolidSphere( radius, 25, 25 );
    }
    glPopMatrix();

    glPushMatrix();
    {
        glRotatef( yRotated, 0.0, 2.0, 0.0 );
        glTranslatef( 5.0, 0.0, 0.0 );
        GLfloat qaLightPosition[] = {1, 1, 1, 1};
        glLightfv( GL_LIGHT0, GL_POSITION, qaLightPosition );
        GLfloat emitLight[] = {0.9, 0.9, 0.9, 0.9};
        glMaterialfv( GL_FRONT_AND_BACK, GL_EMISSION, emitLight ); // Make sphere glow (emissive)
        glutSolidSphere( radius / 6, 25, 25 );
        GLfloat Noemit[] = {0.0, 0.0, 0.0, 1.0};
        glMaterialfv( GL_FRONT_AND_BACK, GL_EMISSION, Noemit );
    }
    glPopMatrix();
    

	// Text
	glRasterPos3f(-1.3,5.0,0);
	char msg1[]="Space Shooter";
	for(int i=0;i<strlen(msg1);i++)
	//drawText(text.data(), text.size(), 50, 473, GLUT_BITMAP_TIMES_ROMAN_24 msg1[i])
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg1[i]);
	
	glRasterPos3f(-5.0,4.0,0);
	char msg2[]="Presented By:";
	for(int i=0;i<strlen(msg2);i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, msg2[i]);
		
	glRasterPos3f(-5.0,3.7,0);
	char msg3[]="Chun Wei Yi";
	for(int i=0;i<strlen(msg3);i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, msg3[i]);
		
	glRasterPos3f(-5.0,3.4,0);
	char msg4[]="Foh Wei Lian Willian";
	for(int i=0;i<strlen(msg4);i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, msg4[i]);
		
	glRasterPos3f(-5.0,3.1,0);
	char msg5[]="Tan Ee Yee";
	for(int i=0;i<strlen(msg5);i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, msg5[i]);
		
	glRasterPos3f(-5.0,2.8,0);
	char msg6[]="Yeoh Pei Xian";
	for(int i=0;i<strlen(msg6);i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, msg6[i]);
		
	glColor3f(2.0, 1.5, 0.9);
	glRasterPos3f(-1.2,-3.7,1);
	char msg7[]="To start, press 's'";
	for(int i=0;i<strlen(msg7);i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, msg7[i]);
	
	glColor3f(0.8, 1.5, 0.9);
	glRasterPos3f(-1.2,-4.0,1);
	char msg8[]="To exit, press 'e'";
	for(int i=0;i<strlen(msg8);i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, msg8[i]);
    glutSwapBuffers();
}


int main(){
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB| GLUT_DEPTH);//single frame buffer with rgb colors
	glutInitWindowSize(window.width, window.height); //opengl windows size
	glutInitWindowPosition(window.posX, window.posY);//windows position on the screen
	glutCreateWindow(window.title);//opengl windows title
	glutKeyboardFunc(keyboardControl);
	glutSpecialFunc(keyboardControl2);
	glutMouseFunc(mouseControl);
	glutMotionFunc(mouseMoveControl);
	
    glEnable(GL_DEPTH_TEST);	
	init();  //put this the blue background appears
    xRotated = yRotated = zRotated = 0.0;
    glutDisplayFunc(menuDisplay);
  
    glutTimerFunc( 0, timer, 0 );

    glutMainLoop();
	system("PAUSE"); //stop frame
	return 0;//close program
}



void renderBackground() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(window.r, window.g, window.b, window.a);//set bg color with rgba

	//render code here
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, window.width * window.canvasRatio, 0, window.height * window.canvasRatio); // Set canvas to 1600x1900 pixels.

	glClear(GL_COLOR_BUFFER_BIT); // Load frame buffer.

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	int e = 251.0, f = 176.0;

	glClearColor(window.r, window.g, window.b, window.a);

	for (int i = 1100; i > 0; i -= 7) {
		if (e > 120 || f > 80) {
			glColor3f(e-- / 255.0f, 180 / 255.0f, 59.0 / 255.0f);
		}

		planet.drawCircle(800, -640, i, 500, 0, 1, 1);

	}
	//stars
	glColor3f(230.0 / 255.0f, 201.0 / 255.0f, 157.0 / 255.0f);
	star.drawCircle(260, 1750, 5, 500, 0, 1, 1);

	glColor3f(230.0 / 255.0f, 201.0 / 255.0f, 157.0 / 255.0f);
	star.drawCircle(480, 1780, 5, 500, 0, 1, 1);

	glColor3f(230.0 / 255.0f, 201.0 / 255.0f, 157.0 / 255.0f);
	star.drawCircle(1460, 750, 5, 500, 0, 1, 1);

	glColor3f(230.0 / 255.0f, 201.0 / 255.0f, 157.0 / 255.0f);
	star.drawCircle(80, 800, 5, 500, 0, 1, 1);

	glColor3f(230.0 / 255.0f, 201.0 / 255.0f, 157.0 / 255.0f);
	star.drawCircle(300, 1000, 5, 500, 0, 1, 1);

	glColor3f(230.0 / 255.0f, 201.0 / 255.0f, 157.0 / 255.0f);
	star.drawCircle(1500, 1200, 5, 500, 0, 1, 1);

	glColor3f(1.0f, 1.0f, 1.0f);
	score = game ? game->getScore() : score;
	textPoints = "points: " + std::to_string(score); //how to convert to string?

	text.drawText(textPoints.data(), textPoints.size(), 10, 580, GLUT_BITMAP_9_BY_15);
}

void mouseControl(GLint button, GLint status, int x, int y) {
	y = window.height - y;
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (status == GLUT_DOWN && !control.leftMouseIsPressed) {
			control.mousePosX = x;
			control.mousePosY = y;
			control.diffPosX = 0;
			control.diffPosY = 0;
			control.leftMouseIsPressed = true;
			control.keyboardAction = false;
			if (game)
				game->HandleUserInput(control);
		}
		else if (status == GLUT_UP && control.leftMouseIsPressed) {
			control.leftMouseIsPressed = false;
			control.keyboardAction = false;
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if (status == GLUT_DOWN && !control.rightMouseIsPressed) {
			control.mousePosX = x;
			control.mousePosY = y;
			control.diffPosX = 0;
			control.diffPosY = 0;
			control.rightMouseIsPressed = true;
			control.keyboardAction = false;
			if (game)
				game->HandleUserInput(control);
		}
		else if (status == GLUT_UP && control.rightMouseIsPressed) {
			control.rightMouseIsPressed = false;
			control.keyboardAction = false;
		}
		break;
	}
	glutPostRedisplay();
}

void mouseMoveControl(GLint x, GLint y) {
	y = window.height - y;
	control.diffPosX = x - control.mousePosX;
	control.diffPosY = y - control.mousePosY;
	if (control.leftMouseIsPressed || control.rightMouseIsPressed) {
		control.keyboardAction = false;
		//character move if the left mouse is pressed
		if (game)
			game->HandleUserInput(control);
	}
	control.mousePosX = x;
	control.mousePosY = y;

	glutPostRedisplay();
}

void keyboardControl(unsigned char key, GLint x, GLint y) {
	//character move if the respective key is pressed
	bool valid = false;

	switch (key) {
	case 'w':
	case 'W':
		control.keyboardAction = true;
		control.keyPressed = (int)'w';
		if (game)
			game->HandleUserInput(control);
		break;
	case 's':
	case 'S':
 		if(game){
			control.keyboardAction = true;
			control.keyPressed = (int) 's';
			valid = true;
			
			glDisable(GL_DEPTH_TEST);
			glDisable(GL_LIGHTING);
			glDisable(GL_LIGHT0);
			glutDisplayFunc(render);		
		}
		else{
			game = new GameEngine();
			game->StartGame();
		}
		break;
	case 'e':
	case 'E':
 		if(!game)
 			exit(0);	
 		break;
	case 'a':
	case 'A':
		control.keyboardAction = true;
		control.keyPressed = (int)'a';
		valid = true;
		break;
	case 'd':
	case 'D':
		control.keyboardAction = true;
		control.keyPressed = (int)'d';
		valid = true;
		break;
	case 32:	//space
	case 13:	//enter
		control.keyboardAction = true;
		control.keyPressed = (int)'q';
		valid = true;
		break;
	}

	if (valid && game)
		game->HandleUserInput(control);
	
	glutPostRedisplay();
}

void keyboardControl2(int key, GLint x, GLint y) {
	//character move if the respective key is pressed
	bool valid = false;

	switch (key) {
	case GLUT_KEY_UP:
		control.keyboardAction = true;
		control.keyPressed = (int)'w';
		valid = true;
		break;
	case GLUT_KEY_DOWN:
		control.keyboardAction = true;
		control.keyPressed = (int)'s';
		valid = true;
		break;
	case GLUT_KEY_LEFT:
		control.keyboardAction = true;
		control.keyPressed = (int)'a';
		valid = true;
		break;
	case GLUT_KEY_RIGHT:
		control.keyboardAction = true;
		control.keyPressed = (int)'d';
		valid = true;
		break;
	}

	if (valid && game)
		game->HandleUserInput(control);

	glutPostRedisplay();
}

void render() {
	renderBackground();

	/*
		Let the game engine to render the characters
	*/
	if (game && game->getGameStatus()) {
		game->HandleGameEvent();
		game->RenderGameScreen();
		if(game->getRobot().isAlive())
			game->StartGame();
		glutPostRedisplay();
	}
	else {
		if (game)
			delete game;
		game = NULL;
		glutDisplayFunc(menuDisplay);
	}

	glFlush();	// clear all gl exexecution
	glutSwapBuffers();
	glFinish();	//bloack until all gl exe are completed	
}
