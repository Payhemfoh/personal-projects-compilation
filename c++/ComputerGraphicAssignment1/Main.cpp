#include <iostream>
#include <gl/glut.h>
#include "Brush.h"

const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 600;
const double PI = 3.14;

void renderWindow();
void renderRobot();
void drawBackground();
void drawRobotArm();
void drawRobotHead();
void drawRobotLeg();
void drawRobotLowerBody();
void drawRobotUpperBody();

int main() {
	//set window display mode to single window with rgba color
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);

	//set initial window size
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

	//initialize window position to top left corner
	glutInitWindowPosition(0, 0);

	//create window with title
	glutCreateWindow("Robot");

	//setup render function
	glutDisplayFunc(renderWindow);

	//loop render function
	glutMainLoop();
	return 0;
}

void renderWindow() {
	//set background color
	glClearColor(17/255.0f,85/255.0f,153/255.0f,1.0f);

	//set canvas size
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//handle resolution
	gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);

	//clear display buffer
	glClear(GL_COLOR_BUFFER_BIT);

	//initialize the point variables to perform auto convertion between drawing and screen size
	Point::setDrawingAndScreenSize(2133.0f, 2133.0f, 600.0f, 600.0f);

	drawBackground();
	renderRobot();

	//clear gl execute command
	glFlush();
	glFinish();
}

void renderRobot() {
	//render robot part-by-part
	drawRobotLeg();

	drawRobotLowerBody();

	drawRobotArm();
	drawRobotHead();
	drawRobotUpperBody();
}

void drawBackground() {
	//render background components
	Brush bg_brush(37, 107, 180);

	//render background by drawing point to create gradient effect
	for (float i = 0; i < 2133; ++i) {
		for (float j = 0; j < 2133; ++j) {
			GLfloat percent = (i + j) / (2133 + 2133);
			GLfloat red = (42 - 30) * percent;
			GLfloat green = (82 - 60) * percent;
			GLfloat blue = (152 - 114) * percent;
			bg_brush.setColor(42 - red, 82 - green, 152 - blue);
			bg_brush.drawPoint(Point(i, j), 1);
		}
	}

	bg_brush.setColor(37, 107, 180);
	bg_brush.drawTriangle(Point(0, 200), Point(1400, 100), Point(0, 650));

	bg_brush.setColor(29, 84, 142);
	bg_brush.drawTriangle(Point(2180, 400), Point(818, 476), Point(2180,870));

	bg_brush.setColor(21, 62, 104);
	bg_brush.drawTriangle(Point(0, 920), Point(1400, 820), Point(0, 1400));

	bg_brush.setColor(14, 42, 70);
	bg_brush.drawPolygon(Point(2038, 1319), Point(460, 0).getConvertX(), 6);

	bg_brush.setColor(77, 77, 77);
	bg_brush.drawRectangle(Point(0, 1400), Point(2133, 1400), Point(2133, 2133), Point(0, 2133));

	bg_brush.setColor(31, 31, 31);
	bg_brush.drawTriangle(Point(2133, 1400), Point(2133, 2133), Point(0, 2133));

	//apply matrix transform to mode pentagon down 10 pixel along y axis
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, -10.0f, 0.0f);
	bg_brush.drawPolygon(Point(0, 1777), Point(404, 0).getConvertX(), 5, -60.0f);
	glLoadIdentity();
}

void drawRobotArm() {
	Brush rb_brush(24, 24, 24);

	//arm
	rb_brush.drawPolygon(Point(681, 1098), Point(129, 0).getConvertX(), 3, 30, 1.0f, 1.1f);

	rb_brush.setColor(179, 98, 27);
	rb_brush.drawRectangle(Point(766, 581), Point(940, 581), Point(1213, 960), Point(1090, 1037));
	rb_brush.drawRectangle(Point(748, 581), Point(895, 581), Point(696, 1060), Point(602, 1060));

	rb_brush.setColor(212, 126, 49);
	rb_brush.drawRectangle(Point(764, 584), Point(911, 584), Point(720, 1063), Point(618, 1063));

	rb_brush.setColor(88, 88, 88);
	rb_brush.drawPolygon(Point(664, 1104), Point(129, 0).getConvertX(), 3, 30, 1.0f, 1.1f);

	rb_brush.setColor(0.0f, 0.0f, 0.0f);
	rb_brush.drawLine(Point(737, 1000), Point(701, 1194));
}

void drawRobotHead() {
	Brush rb_brush(133, 112, 106);

	//head
	rb_brush.drawRectangle(Point(884, 672), Point(1163, 782), Point(1163, 1426), Point(884, 1305));

	rb_brush.setColor(84, 84, 82);
	rb_brush.drawRectangle(Point(1331, 666), Point(1331, 1294), Point(1153, 1437), Point(1153, 771));


	rb_brush.setColor(37, 37, 37);
	rb_brush.drawRectangle(Point(911, 762), Point(1114, 830), Point(1114, 1167), Point(911, 1072));

	rb_brush.setColor(42, 42, 42);
	rb_brush.drawRectangle(Point(1309, 717), Point(1184, 786), Point(1184, 1137), Point(1309, 1025));

	rb_brush.setColor(84, 84, 82);
	rb_brush.drawTriangle(Point(1155, 774), Point(1155, 995), Point(1073, 820));

	rb_brush.setColor(53, 52, 49);
	rb_brush.drawTriangle(Point(886, 708), Point(886, 929), Point(802, 720));

	rb_brush.setColor(40, 39, 36);
	rb_brush.drawRectangle(Point(1068, 590), Point(802, 720), Point(1068, 826), Point(1338, 665));

	rb_brush.setColor(64, 215, 238);
	rb_brush.drawPolygon(Point(968, 880), Point(12, 0).getConvertX(), 360, 0, 0.5f, 4.0f);
	rb_brush.drawPolygon(Point(1046, 902), Point(12, 0).getConvertX(), 360, 0, 0.5f, 4.0f);
}

void drawRobotLeg() {
	//render leg
	Brush rb_brush(112, 112, 112);
	rb_brush.drawRectangle(Point(873, 1354), Point(973, 1354), Point(973, 1554), Point(873, 1554));
	rb_brush.drawRectangle(Point(1109, 1391), Point(1209, 1391), Point(1209, 1591), Point(1109, 1591));

	rb_brush.setColor(6, 6, 6);
	rb_brush.drawTriangle(Point(973, 1554), Point(973, 1354), Point(1073, 1354));
	rb_brush.drawTriangle(Point(1209, 1591), Point(1209, 1391), Point(1309, 1391));
}

void drawRobotLowerBody() {
	//body
	Brush rb_brush(104, 97, 3);
	rb_brush.drawRectangle(Point(1021, 1141), Point(1171, 916), Point(1409, 1002), Point(1420, 1192));

	rb_brush.setColor(122, 84, 11);
	rb_brush.drawRectangle(Point(1068, 850), Point(1180, 793), Point(1519, 930), Point(1380, 998));

	rb_brush.setColor(210, 145, 20);
	rb_brush.drawRectangle(Point(1084, 830), Point(1210, 778), Point(1535, 900), Point(1390, 983));

	rb_brush.setColor(193, 180, 6);
	rb_brush.drawRectangle(Point(822, 1385), Point(822, 1283), Point(955, 1024), Point(1081, 1166));

	rb_brush.setColor(168, 157, 5);
	rb_brush.drawTriangle(Point(1159, 1413), Point(1424, 1210), Point(1380, 1007));
}

void drawRobotUpperBody() {
	//side body
	Brush rb_brush(235, 221, 1);
	rb_brush.drawRectangle(Point(822, 1283), Point(1160, 1415), Point(1160, 1550), Point(826, 1415));

	rb_brush.setColor(208, 194, 6);
	rb_brush.drawTriangle(Point(1160, 1415), Point(1424, 1268), Point(1400, 1007));
	rb_brush.drawRectangle(Point(1433, 1239), Point(1427, 1392), Point(1160, 1550), Point(1160, 1415));

	rb_brush.setColor(122, 84, 11);
	rb_brush.drawRectangle(Point(1380, 998), Point(1500, 923), Point(1553, 1245), Point(1430, 1338));

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	rb_brush.rotate(Point(1393, 1285), 120.0f);
	rb_brush.drawPolygon(Point(1393, 1285), Point(154, 0).getConvertX(), 360, 120.0f, 0.5f, 1.1f);
	rb_brush.finishRotation();

	rb_brush.setColor(216, 151, 36);
	rb_brush.drawRectangle(Point(1395, 983), Point(1535, 900), Point(1567, 1238), Point(1456, 1329));


	rb_brush.rotate(Point(1404, 1293), 120.0f);
	rb_brush.drawPolygon(Point(1404, 1293), Point(154, 0).getConvertX(), 360, 120.0f, 0.5f, 1.1f);
	rb_brush.finishRotation();

	rb_brush.setColor(230, 161, 38);
	rb_brush.rotate(Point(1400, 1306), 120.0f);
	rb_brush.drawPolygon(Point(1400, 1306), Point(95, 0).getConvertX(), 360, 120.0f, 0.6f, 1.3f);
	rb_brush.finishRotation();

	rb_brush.setColor(250, 175, 41);
	rb_brush.rotate(Point(1408, 1310), 120.0f);
	rb_brush.drawPolygon(Point(1408, 1310), Point(71, 0).getConvertX(), 360, 120.0f, 0.6f, 1.3f);
	rb_brush.finishRotation();
}