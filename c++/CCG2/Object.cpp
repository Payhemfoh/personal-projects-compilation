#include "Object.h"

const double PI = acos(-1);

Object::Object()
	:x(0),y(0)
{}

Object::Object(GLfloat x, GLfloat y) 
	:x(x),y(y)
{}

Object::~Object(){}


void Object::drawCircle(GLfloat x, GLfloat y, GLfloat radius, 
	GLint side, GLfloat orientation, GLfloat width, GLfloat height){
	if(side >= 3){
		glPushMatrix();
		GLint xp, yp;
		glBegin(GL_POLYGON);
		for(int i=0; i<side; i++){
			xp = (int) (x + width*radius*cos(orientation + 2*3.1415965/side*i));
			yp = (int) (y + width*radius*sin(orientation + 2*3.1415965/side*i));
			glVertex2i(xp, yp);				
		}
		glEnd();
		glPopMatrix();
	}
	else{
		cerr << "error spawn circle" << endl;
	}
}

void Object::drawPoint(GLfloat size) {
	//push drawing to memory
	glPushMatrix();

	//configure point size
	glPointSize(size);

	//drawing point
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();

	// pop drawing from memory
	glPopMatrix();
}
	
	
void Object::drawLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {
	glPushMatrix();

	//drawing point
	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();

	glPopMatrix();
}
	
	
	
				   
void Object::drawTriangle(GLfloat x1, GLfloat y1,
			      GLfloat x2, GLfloat y2,
				  GLfloat x3, GLfloat y3){
				  	glPushMatrix();
				  	glBegin(GL_TRIANGLES);
				  		glVertex2i(x1, y1);
						glVertex2i(x2, y2);
						glVertex2i(x3, y3);
					glEnd();
					glPopMatrix();	
				  }	

void Object::drawQuad (GLfloat x1, GLfloat y1,
			   GLfloat x2, GLfloat y2,
			   GLfloat x3, GLfloat y3,
			   GLfloat x4, GLfloat y4){
			   	glPushMatrix();
			   	glBegin(GL_QUADS);
			   		glVertex2i(x1, y1);
				   glVertex2i(x2, y2);
				   glVertex2i(x3, y3);
				   glVertex2i(x4, y4);
				glEnd();
				glPopMatrix();	
			}

void Object::scale(GLfloat sX, GLfloat sY){
	this->x = this->x * sX;
	this->y = this->y * sY;
}	
	
void Object::drawText(const char *text, GLint length, GLint x, GLint y, void *font){
	glMatrixMode(GL_PROJECTION);
	double *matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	
	glLoadIdentity();
	glOrtho(0, 800, 0, 600, -5, 5);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glPushMatrix();
		glLoadIdentity();
		glRasterPos2i(x,y);
		for(int i=0; i<length; i++){
			glutBitmapCharacter(font, (int)text[i]);
		}
	glPopMatrix();
	
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
}	

void Object::drawRegularPolygon(GLfloat x, GLfloat y, GLfloat radius, GLint side, GLfloat orientation, GLfloat width, GLfloat height) {
	if (side > 3) {
		GLint xp, yp;
		glPushMatrix();

		//drawing point
		glBegin(GL_POLYGON);
		for (int i = 0; i < side; ++i) {
			xp = (int)(x + width * radius * cos(orientation + 2 * PI / side * i));
			yp = (int)(y + width * radius * sin(orientation + 2 * PI / side * i));
			glVertex2i(xp, yp);
		}
		glEnd();

		glPopMatrix();
	}
	else {
		std::cerr << "Cannot render polygon with side less than 3!" << std::endl;
	}
}