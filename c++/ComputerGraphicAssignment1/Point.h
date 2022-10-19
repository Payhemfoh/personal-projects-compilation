#ifndef POINT_H
#define POINT_H
#include <gl/glut.h>

/*
	Class for store the point information which contains x and y in GLfloat
	To be used during the rendering of the primitive shapes
	To use the auto convertion function, please use setDrawingAndScreenSize to set the
	drawing and window size.
*/
class Point
{
private:
	GLfloat x;
	GLfloat y;
	static GLfloat drawingWidth;
	static GLfloat drawingHeight;
	static GLfloat windowWidth;
	static GLfloat windowHeight;
public:
	/*
		static method to set the drawing and screen size to perform convertion automatically
		@param drawingWidth - the width of the bitmap drawing 
		@param drawinHeight - the height of the bitmap drawing 
		@param windowWidth - the width of the gl rendering screen 
		@param windowHeight - the width of the gl rendering screen
	*/
	void static setDrawingAndScreenSize(GLfloat drawingWidth,GLfloat drawingHeight, GLfloat windowWidth, GLfloat windowHeight);

	/*
		constructor with x and y position
		@param x - horizontal position of point
		@param y - vertical position of point
	*/
	Point(GLfloat x, GLfloat y);

	/*
		getter to get the horizontal position of point
		@return horizontal position of point
	*/
	GLfloat getX();

	/*
		getter to get the vertical position of point
		@return vertical position of point
	*/
	GLfloat getY();

	/*
		getter to get the horizontal position of point after the convertion from drawing size to window size
	*/
	GLfloat getConvertX();

	/*
		getter to get the horizontal position of point after the convertion from drawing size to window size
		and inverted y for gl rendering
	*/
	GLfloat getConvertY();
};

#endif