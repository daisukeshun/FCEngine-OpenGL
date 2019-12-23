#include <GL/freeglut.h>
void Init(){

	glClearColor(0.f, 0.f, 0.f, 0.f);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);

	glOrtho(-1.f, 1.f, -1.f, 1.f, -1.f, 1.f);

	glEnable(GL_NORMALIZE);
}
