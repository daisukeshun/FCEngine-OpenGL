#ifndef DISPLAY_H
#define DISPLAY_H

#include "Mesh.h"
#include "Camera.h"
#include "print.h"

#include <GL/gl.h>
#include <GL/glu.h>

#include "Collision.h"

static void Display(Mesh& mesh, Camera& camera){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//print(camera.getLookDistance().length);

	/*
	GLfloat camX = camera.position.x;//camera.lookVector.length * -sinf(camera.rotation.x) * cosf(camera.rotation.y);
	GLfloat camY = camera.position.y;// 3 * sinf(camera.rotation.y) * cosf(camera.rotation.x);
	GLfloat camZ = camera.position.z;//-camera.lookVector.length * cosf(camera.rotation.x) * cosf(camera.rotation.y);
	*/


	gluLookAt(
			camera.position.x, camera.position.y, camera.position.z,
			cosf(camera.look.x), 0 ,sinf(camera.look.x),
			0, 1, 0
			);

	glTranslatef(mesh.position.x, mesh.position.y, mesh.position.z);

	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
		glColor3f(1, 0, 0);
		glVertex3f(0,0,0);
		glVertex3f(1,0,0);
		glColor3f(0, 1, 0);
		glVertex3f(0,0,0);
		glVertex3f(0,1,0);
		glColor3f(0, 0, 1);
		glVertex3f(0,0,0);
		glVertex3f(0,0,1);
	glEnd();
	glRotatef(mesh.rotation.x, 1, 0, 0);
	glRotatef(mesh.rotation.y, 0, 1, 0);
	glRotatef(mesh.rotation.z, 0, 0, 1);

	glEnable(GL_LIGHTING);
	glBegin(GL_TRIANGLES);
		for (int i = 0; i < mesh.polygonCount; i++)
		{
			glNormal3fv(mesh.vn[i].array);
			for (int j = 0; j < 3; j++)
			{
				glVertex3fv(mesh.v[i][j].array);
			}
		}
	glEnd();
	for (int i = 0; i < 6; i++)
	{
		glBegin(GL_LINE_LOOP);
			for (int j = 0; j < 4; j++)
			{
				glVertex3fv(mesh.bounds[i].p[j].array);
			}
		glEnd();
	}
}

#endif
