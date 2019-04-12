#pragma once
#include <iostream>
#include <cmath>
#include <vector>

#include"glut.h"
#include "Matrix.h"
#include "Point2D.h"


static bool bWire = false;
static bool btranslate = false;
static bool brotate = false;
static bool bscale = false;
constexpr float PI = 3.1415926f;
std::vector<Point2D<float>> GraphData;
 Matrix3by3<float> Mat_Composed;

void InitTriangle();
void RenderAxis();
void RenderScene();
void Reshape(int Width, int Height);
void myKey(unsigned char key, int x, int y);
void mySpecialKey(int key, int x, int y);
void myMouse(int button, int state, int x, int y);
void renderTriangle(std::vector<Point2D<float>> GraphData);
std::vector<Point2D<float>> translatePoint2D(Matrix3by3<float> matcomposed, std::vector<Point2D<float>> PointData);

int main() {

	
	InitTriangle();
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("GLRect");

	glutDisplayFunc(RenderScene);
	glutReshapeFunc(Reshape);

	glutKeyboardFunc(myKey);
	glutSpecialFunc(mySpecialKey);
	glutMouseFunc(myMouse);

	glClearColor(1, 1, 1, 1);

	glutMainLoop();

	return 0;
}

void InitTriangle()
{
	GraphData.push_back(Point2D<float>(20, 20));
	GraphData.push_back(Point2D<float>(0, 0));
	GraphData.push_back(Point2D<float>(20, 0));
}

void RenderAxis()
{
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(0, -100);
	glVertex2f(0, 100);
	glVertex2f(100, 0);
	glVertex2f(-100, 0);
	glEnd();
}


void RenderScene()
{

	glClear(GL_COLOR_BUFFER_BIT);
	if (bWire)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	}
	else
	{

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	}

	RenderAxis();
	renderTriangle(GraphData);

	glutSwapBuffers();
}

void Reshape(int Width, int Height)
{
	GLfloat aspectRatio;

	// Prevent a divide by zero
	if (Height == 0)
		Height = 1;

	// Set Viewport to window dimensions
	glViewport(0, 0, Width, Height);

	// Reset coordinate system
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Establish clipping volume (left, right, bottom, top, near, far)
	aspectRatio = (GLfloat)Width / (GLfloat)Height;
	if (Width <= Height)
		glOrtho(-100.0, 100.0, -100 / aspectRatio, 100.0 / aspectRatio, 1.0, -1.0);
	else
		glOrtho(-100.0 * aspectRatio, 100.0 * aspectRatio, -100.0, 100.0, 1.0, -1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void myKey(unsigned char key, int x, int y)
{
	if (key == 'w' || key == 'W')
	{
		bWire = !bWire;
	}
	if (key == 't' || key == 'T')
	{
		btranslate = !btranslate;
		if (btranslate)
		{
			Mat_Composed = Matrix_SetIdentity(Mat_Composed);
			Mat_Composed = Translate2D(20, 20, Mat_Composed);
			GraphData = translatePoint2D(Mat_Composed, GraphData);
		}
		else
		{
			Mat_Composed = Matrix_SetIdentity(Mat_Composed);
			Mat_Composed = Translate2D(-20, -20, Mat_Composed);
			GraphData = translatePoint2D(Mat_Composed, GraphData);
		}
	}
	if (key == 'r' || key == 'R')
	{
		brotate = !brotate;
		if (brotate)
		{
			Mat_Composed = Matrix_SetIdentity(Mat_Composed);
			Mat_Composed = Rotate2D(Point2D<float>(0,0),PI/2, Mat_Composed);
			GraphData = translatePoint2D(Mat_Composed, GraphData);
		}
		else
		{
			Mat_Composed = Matrix_SetIdentity(Mat_Composed);
			Mat_Composed = Rotate2D(Point2D<float>(0, 0), -PI/2, Mat_Composed);
			GraphData = translatePoint2D(Mat_Composed, GraphData);
		}
	}
	if (key == 's')
	{
		Mat_Composed = Matrix_SetIdentity(Mat_Composed);
		Mat_Composed = Scale2D(0.5, 0.5, Point2D<float>(0,0),Mat_Composed);
		GraphData = translatePoint2D(Mat_Composed, GraphData);
	}

	if (key == 'S')
	{
		Mat_Composed = Matrix_SetIdentity(Mat_Composed);
		Mat_Composed = Scale2D(2, 2, Point2D<float>(0, 0), Mat_Composed);
		GraphData = translatePoint2D(Mat_Composed, GraphData);
	}
	glutPostRedisplay();
}

void mySpecialKey(int key, int x, int y)
{
}

void myMouse(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN && button == GLUT_RIGHT_BUTTON)
	{
		exit(0);
	}

	glutPostRedisplay();
}

void renderTriangle(std::vector<Point2D<float>> GraphData)
{
	glBegin(GL_TRIANGLES);
	for (auto iter = GraphData.begin(); iter != GraphData.end(); iter++)
	{
		glVertex2f(iter->getcoorX(), iter->getcoory());
	}
	glEnd();
}



std::vector<Point2D<float>> translatePoint2D(Matrix3by3<float> matcomposed, std::vector<Point2D<float>> PointData) {
	std::vector<Point2D<float>> PointData_trans;

	float temp_elem_x = 0, temp_elem_y = 0;
	for (auto iter = PointData.begin(); iter != PointData.end(); iter++)
	{
			
				temp_elem_x = matcomposed.getElem(0, 0)*iter->getcoorX()+ matcomposed.getElem(0, 1)*iter->getcoory()+ matcomposed.getElem(0, 2);
				temp_elem_y = matcomposed.getElem(1, 0)*iter->getcoorX() + matcomposed.getElem(1, 1)*iter->getcoory() + matcomposed.getElem(1, 2);
			PointData_trans.push_back(Point2D<float>(temp_elem_x, temp_elem_y));
			temp_elem_x = 0;
			temp_elem_y = 0;
	}
	return PointData_trans;
}