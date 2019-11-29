#ifndef DISPLAY_H
#define DISPLAY_H

#include "Mesh.h"

#include <GL/gl.h>
#include <GL/glu.h>

#include "Collision.h"

static void Display(Mesh& mesh, const float angle){
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	float position[4] = {0, 0, -0.1, 0.1};
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	
	//glDisable(GL_LIGHTING);
	glTranslatef(mesh.position.x, mesh.position.y, mesh.position.z);
	glRotatef(angle, 0, 1, 0);
	glBegin(GL_TRIANGLES);
		for (int i = 0; i < mesh.polygonCount; i++)
		{
			glNormal3fv(mesh.vn[i].array);
			for (int j = 0; j < 3; j++)
			{
				glColor3f(1.0, 1.0, 0.0);
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
