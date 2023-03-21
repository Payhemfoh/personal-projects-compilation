#include "Brush.h"

const double Brush::PI = acos(-1);

Brush::Brush() 
{
	this->setColor(0, 0, 0);
}

Brush::Brush(int r, int g, int b) {
	
	this->setColor(r, g, b);
}

void Brush::setColor(int r, int g, int b) {
	this->r = r;
	this->g = g;
	this->b = b;

	GLfloat red = (r%256) / 255.0f;
	GLfloat green = (g%256) / 255.0f;
	GLfloat blue = (b%256) / 255.0f;
	glColor3f(red, green, blue);
}

void Brush::drawTriangle(Point p1,Point p2,Point p3) {
	glPushMatrix();

	glBegin(GL_TRIANGLES);
		glVertex2f(p1.getConvertX(), p1.getConvertY());
		glVertex2f(p2.getConvertX(), p2.getConvertY());
		glVertex2f(p3.getConvertX(), p3.getConvertY());
	glEnd();

	glPopMatrix();
}

void Brush::drawRectangle(Point p1, Point p2, Point p3, Point p4) {
	glPushMatrix();

	glBegin(GL_QUADS);
	glVertex2f(p1.getConvertX(), p1.getConvertY());
	glVertex2f(p2.getConvertX(), p2.getConvertY());
	glVertex2f(p3.getConvertX(), p3.getConvertY());
	glVertex2f(p4.getConvertX(), p4.getConvertY());
	glEnd();

	glPopMatrix();
}

bool Brush::drawPolygon(Point center, GLfloat radius, GLint sides, GLfloat rotation, GLfloat width , GLfloat height) {
	bool status = true;
	GLint xp, yp;
	if (sides > 2) {
		glPushMatrix();
		glBegin(GL_POLYGON);
		for (int i = 0; i < sides; ++i) {
			xp = center.getConvertX() + (width * radius * cos(rotation + 2 * PI / sides * i));
			yp = center.getConvertY() + (height * radius * sin(rotation + 2 * PI / sides * i));
			glVertex2f(xp, yp);
		}
		glEnd();
		glPopMatrix();
	}
	else
		status = false;

	return status;
}

void Brush::drawLine(Point p1, Point p2) {
	glPushMatrix();
	glBegin(GL_LINE);
		glVertex2f(p1.getConvertX(), p1.getConvertY());
		glVertex2f(p2.getConvertX(), p2.getConvertY());
	glEnd();
	glPopMatrix();
}

void Brush::drawPoint(Point p, GLfloat size) {
	glPushMatrix();
	glPointSize(size);
	glBegin(GL_POINTS);
	glVertex2f(p.getConvertX(), p.getConvertY());
	glEnd();
	glPopMatrix();
}

void Brush::rotate(Point center, GLfloat degree) {
	glTranslatef(center.getConvertX(), center.getConvertY(), 0.0f);
	glRotatef(degree, 0.0f, 0.0f, 1.0f);
	glTranslatef(-center.getConvertX(), -center.getConvertY(), 0.0f);
}

void Brush::finishRotation() {
	glLoadIdentity();
}