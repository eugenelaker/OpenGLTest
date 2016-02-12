#include <glut.h>
#include <GL/glu.h>


void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.0);
	glRectf(-25.0, 25.0, 25.0, -25.0);
	glFlush();
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
		glOrtho(-100.0, 100.0, -100.0 / aspectRatio, 100.0 / aspectRatio, -1.0, 1.0);
	}
	else {
		glOrtho(-100.0 * aspectRatio, 100.0 * aspectRatio, -100.0 , 100.0 , 1.0, -1.0);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void SetupRC()
{
	glClearColor(1.0, 0.0, 0.0, 1.0);
}

void main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("OpenGL Test");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	SetupRC();
	glutMainLoop();
}