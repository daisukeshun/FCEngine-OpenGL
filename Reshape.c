#include <GL/freeglut.h>
void reshape(int w, int h){
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(
			45.0,
			(GLfloat)w/(GLfloat)h,
			0.1f, 100.0f);

}
