#ifndef _OBJECT_H_
#define _OBJECT_H_
#include <iostream>
#include "math.h"
#include <GL/glut.h>

using namespace std;

class Object{
	public:
	GLfloat x, y;

	Object();
	Object(GLfloat x, GLfloat y);
	~Object();

	void drawCircle(GLfloat x, GLfloat y, GLfloat radius,
	GLint side, GLfloat orientation, GLfloat width, GLfloat height);
	
	void drawQuad(GLfloat x1, GLfloat y1,
				  GLfloat x2, GLfloat y2,
				  GLfloat x3, GLfloat y3,
				  GLfloat x4, GLfloat y4);	
	
	void drawTriangle(GLfloat x1, GLfloat y1,
					  GLfloat x2, GLfloat y2,
					  GLfloat x3, GLfloat y3);	
					  
	void scale(GLfloat sX, GLfloat sY);
						  				  
	void drawPoint(GLfloat size);	
	
	void drawLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
	
	void drawRegularPolygon(GLfloat x, GLfloat y, GLfloat radius, 
							GLint side, GLfloat orientation, GLfloat width, GLfloat height);

	void drawText(const char *text, GLint length, GLint x, GLint y, void *font);							
};


#endif
