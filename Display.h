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

	glTranslatef(mesh.position.x, mesh.position.y, mesh.position.z - 2);
	glRotatef(angle, 0, 1, 0);


	glColor3ub(255, 255, 255);
	glBegin(GL_TRIANGLES);
		for (int i = 0; i < mesh.polygonCount; i++)
		{
			glNormal3f(
				mesh.vn[i].x, 
				mesh.vn[i].y, 
				mesh.vn[i].z);
			for (int j = 0; j < 3; j++)
			{

				glVertex3f(
					mesh.v[i][j].x,
					mesh.v[i][j].y,
					mesh.v[i][j].z
					);
				
			}
		}
		
	glEnd();
}

#endif
