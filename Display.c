#pragma once
#include "Triangle.h"
#include "Camera.h"
#include "MeshLoader.c"

Camera gCam;
GLint meshesCount = 10;
Mesh * mesh;

void drawTriangle(Triangle);
void display(){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);


	/*model view unit matrix*/
	glLoadIdentity();

	gluLookAt(
			gCam.position.x, gCam.position.y, gCam.position.z,
			gCam.look.x + gCam.position.x, gCam.look.y + gCam.position.y , gCam.look.z + gCam.position.z,
			0.f, 1.f, 0.f);

	/*
	glRotatef(gCam.rotation.y, 0.f, 1.f, 0.f);
	glTranslatef(-gCam.position.x, -gCam.position.y, -gCam.position.z);
	*/

	int i;
	unsigned int j;
	for(i = 0; i < meshesCount; i++){
		glPushMatrix();


		glTranslatef(mesh[i].axis.x, mesh[i].axis.y, mesh[i].axis.z);

		glRotatef(mesh[i].axisRotation.x, 1.0f, 0.0f, 0.0f);
		glRotatef(mesh[i].axisRotation.y, 0.0f, 1.0f, 0.0f);
		glRotatef(mesh[i].axisRotation.z, 0.0f, 0.0f, 1.0f);

		glTranslatef(mesh[i].position.x, mesh[i].position.y, mesh[i].position.z);
		/*model view rotate around x,y,z point on angle*/
		glRotatef(mesh[i].rotation.x, 1.0f, 0.0f, 0.0f);
		glRotatef(mesh[i].rotation.y, 0.0f, 1.0f, 0.0f);
		glRotatef(mesh[i].rotation.z, 0.0f, 0.0f, 1.0f);

		glPushMatrix();



		/*model view translation*/


		for(j = 0; j < mesh[i].polygonsCount; j++){
			drawTriangle(mesh[i].polygons[j]);
		}

		glPopMatrix();
		glPopMatrix();
	}


	

	glFlush();
	glutSwapBuffers();
}

void drawTriangle(Triangle t){
	glBegin(GL_TRIANGLES);
		glVertex3fv(t.p[0].arrayForm);
		glVertex3fv(t.p[1].arrayForm);
		glVertex3fv(t.p[2].arrayForm);
	glEnd();
}
