#include "Point.h"

GLfloat Point::drawingHeight = 0.0f;
GLfloat Point::drawingWidth = 0.0f;
GLfloat Point::windowWidth = 0.0f;
GLfloat Point::windowHeight = 0.0f;

Point::Point(GLfloat x,GLfloat y)
	:x(x),y(y)
{}

GLfloat Point::getX() {
	return this->x;
}

GLfloat Point::getY() {
	return this->y;
}

void Point::setDrawingAndScreenSize(GLfloat drawingWidth, GLfloat drawingHeight, GLfloat windowWidth, GLfloat windowHeight) {
	Point::drawingWidth = drawingWidth;
	Point::drawingHeight = drawingHeight;
	Point::windowWidth = windowWidth;
	Point::windowHeight = windowHeight;
}

GLfloat Point::getConvertX() {
	if (Point::drawingWidth == 0 || Point::windowWidth == 0)
		return this->x;
	return (this->x / Point::drawingWidth * Point::windowWidth);
}

GLfloat Point::getConvertY() {
	if (Point::drawingHeight == 0 || Point::windowHeight == 0)
		return this->y;
	return (Point::windowHeight - (this->y / Point::drawingHeight * Point::windowHeight));
}