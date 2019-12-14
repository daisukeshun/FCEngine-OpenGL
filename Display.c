#pragma once
#include "Triangle.h"
#include "Camera.h"
#include "MeshLoader.c"

Camera gCam;
GLfloat rx, ry, rz;
void display(){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);


	/*model view unit matrix*/
	glLoadIdentity();

	glRotatef(gCam.rotation.y, 0.f, 1.f, 0.f);
	glTranslatef(-gCam.position.x, -gCam.position.y, -gCam.position.z);

	glPushMatrix();

	/*model view rotate around x,y,z point on angle*/
	glRotatef(rx, 1.0f, 0.0f, 0.0f);
	glRotatef(ry, 0.0f, 1.0f, 0.0f);
	glRotatef(rz, 0.0f, 0.0f, 1.0f);
	glPushMatrix();
	/*model view translation*/
	glTranslatef(0.0f, 0.0f, -3.5f);
	glBegin(GL_TRIANGLES);
		glVertex3f(0.0f, 0.5f, 0.0f);
		glVertex3f(-0.5f, -0.5f, 0.0f);
		glVertex3f(0.5f, -0.5f, 0.0f);
	glEnd();
	glPopMatrix();
	glPopMatrix();
	






	glFlush();
	glutSwapBuffers();
}
