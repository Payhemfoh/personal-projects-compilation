#ifndef BRUSH_H
#define BRUSH_H
#include <cmath>
#include <gl/glut.h>
#include "Point.h"

/*
	Class for setting color and drawing primitive shapes
*/
class Brush
{
private:
	int r;
	int g;
	int b;
	const static double PI;
public:
	/*
		Default constructor which set the brush color to black
	*/
	Brush();

	/*
		Constructor which allow to set the color
		@param r - red color in range [0-255]
		@param g - green color in range [0-255]
		@param b - blue color in range [0-255]
	*/
	Brush(int r, int g, int b);

	/*
		Method to change the color of brush
		@param r - red color in range [0-255]
		@param g - green color in range [0-255]
		@param b - blue color in range [0-255]
	*/
	void setColor(int r, int g, int b);

	/*
		Method to draw a point on specific point
		@param p1 - point 1 with x and y position
		@param size - the size of point
	*/
	void drawPoint(Point p, GLfloat size);

	/*
		Method to draw a straight line
		@param p1 - point 1 with x and y position
		@param p2 - point 2 with x and y position
	*/
	void drawLine(Point p1, Point p2);

	/*
		Method to draw a triangle
		@param p1 - point 1 with x and y position
		@param p2 - point 2 with x and y position
		@param p3 - point 3 with x and y position
	*/
	void drawTriangle(Point p1, Point p2, Point p3);

	/*
		Method to draw a rectangle
		@param p1 - point 1 with x and y position
		@param p2 - point 2 with x and y position
		@param p3 - point 3 with x and y position
		@param p4 - point 4 with x and y position
	*/
	void drawRectangle(Point p1, Point p2, Point p3, Point p4);

	/*
		Method to draw a polygon
		@param center - the center point of polygon
		@param radius - the radius of the shape
		@param sides - number of sides of the polygon
		@param width - width scaling of the polygon (default = 1)
		@param height - height scaling of the polygon (default = 1)
		@param rotation - angle to be rotated (default = 0)

		@return false when sides less than 2 as polygon required minimum 3 sides
	*/
	bool drawPolygon(Point center, GLfloat radius, GLint sides, GLfloat rotation = 0.0f, GLfloat width=1.0f, GLfloat height=1.0f);

	/*
		Apply rotate to a specific point by degree, method finishRotation() should be called after the rotation
		@param center - the center point of rotation
		@param degree - degree of rotation
	*/
	void rotate(Point center, GLfloat degree);

	/*
		To be called after the rotation to reset the transformation matrix
	*/
	void finishRotation();
};

#endif