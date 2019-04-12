#include <iostream>
#include <cmath>

#include"glut.h"

using namespace std;

static bool bWire = false;

void RenderScene();
void Reshape(int Width, int Height);
void myKey(unsigned char key, int x, int y);
void mySpecialKey(int key, int x, int y);
void myMouse(int button, int state, int x, int y);

int main() {

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
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(0, 70);
	glVertex2f(0, -70);
	glVertex2f(70, 0);
	glVertex2f(-70, 0);
	glEnd();


	glutSwapBuffers();
}
