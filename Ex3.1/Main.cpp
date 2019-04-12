#pragma once
#include <iostream>
#include <cmath>
#include <vector>

#include"glut.h"
#include "Matrix.h"
#include "Point2D.h"
using namespace std;

static bool bWire = true;

std::vector<Point2D<int>> GraphData;


void InitTriangle();
void RenderAxis();
void RenderScene();
void Reshape(int Width, int Height);
void myKey(unsigned char key, int x, int y);
void mySpecialKey(int key, int x, int y);
void myMouse(int button, int state, int x, int y);
void renderTriangle(vector<Point2D<int>> GraphData);

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

	glClearColor(0.8, 0.8, 0.8, 1);

	glutMainLoop();

	return 0;
}

void InitTriangle()
{

	GraphData.push_back(Point2D<int>(20, 20));
	GraphData.push_back(Point2D<int>(0, 0));
	GraphData.push_back(Point2D<int>(20, 0));
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
	glutPostRedisplay();
}

void mySpecialKey(int key, int x, int y)
{
}

void myMouse(int button, int state, int x, int y)
{
}

void renderTriangle(vector<Point2D<int>> GraphData)
{
	glBegin(GL_TRIANGLES);
	for (auto iter = GraphData.begin(); iter != GraphData.end(); iter++)
	{
		glVertex2f(iter->getcoorX(), iter->getcoory());
	}
	glEnd();
}

template<typename T>
Point2D<T>::Point2D(const T x_, const T y_)
	:
	x(x_),
	y(y_)
{
}

