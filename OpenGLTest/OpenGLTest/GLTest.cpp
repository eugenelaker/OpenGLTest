#include <glut.h>
#include <GL/glu.h>

GLfloat x1 = 0.0; GLfloat y1 = 0.0; GLfloat rsize = 25;
GLfloat xstep = 1.0; GLfloat ystep = 1.0;
GLfloat windowWidth; GLfloat windowHeight;

void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.0);
	glRectf(x1, y1, x1+rsize, y1-rsize);
	glutSwapBuffers();
}

void ChangeSize(GLsizei w, GLsizei h)
{
	GLfloat aspectRatio;

	if (!h)
		h = 1;

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	aspectRatio = (GLfloat)w / (GLfloat)h;

	if (w <= h) {
		windowWidth = 100;
		windowHeight = 100 / aspectRatio;
		glOrtho(-100.0, 100.0, -windowHeight, windowHeight, 1.0, -1.0);
	}
	else {
		windowHeight = 100;
		windowWidth = 100 * aspectRatio;
		glOrtho(-windowWidth, windowWidth, -100.0 , 100.0 , 1.0, -1.0);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void SetupRC()
{
	glClearColor(1.0, 0.0, 0.0, 1.0);
}

void TimerFuntion(int value)
{
	if (x1 > windowWidth - rsize || x1 < -windowWidth)
		xstep = -xstep;
	if (y1 > windowHeight || y1 < -windowHeight + rsize)
		ystep = -ystep;

	x1 += xstep;
	y1 += ystep;

	if (x1 > (windowWidth - rsize + xstep))
		x1 = windowWidth - rsize - 1;
	else if (x1 < -(windowWidth + xstep))
		x1 = -windowWidth - 1;
	if (y1 > (windowHeight + ystep))
		y1 = windowHeight - 1;
	else if (y1 < -(windowHeight - rsize + ystep))
		y1 = -windowHeight + rsize - 1;

	glutPostRedisplay();
	glutTimerFunc(10, TimerFuntion, 1);

}

void main()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("OpenGL Test");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutTimerFunc(10, TimerFuntion, 1);
	SetupRC();
	glutMainLoop();
}