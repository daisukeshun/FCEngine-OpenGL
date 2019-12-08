#ifndef DISPLAY_H
#define DISPLAY_H

#include "Mesh.h"
#include "Camera.h"
#include "print.h"

#include <GL/gl.h>
#include <GL/glu.h>

#include "Collision.h"

void DrawMesh(Mesh& mesh, Camera& camera);
static void Display(Mesh * mesh, Camera& camera, const int meshSize){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	for(int i = 0; i < meshSize; i++){
		if(mesh[i].v != NULL){
			DrawMesh(mesh[i], camera);
		}
	}
	/*
	GLfloat camX = camera.position.x;//camera.lookVector.length * -sinf(camera.rotation.x) * cosf(camera.rotation.y);
	GLfloat camY = camera.position.y;// 3 * sinf(camera.rotation.y) * cosf(camera.rotation.x);
	GLfloat camZ = camera.position.z;//-camera.lookVector.length * cosf(camera.rotation.x) * cosf(camera.rotation.y);
	*/

}

void DrawMesh(Mesh& mesh, Camera& camera){
	glLoadIdentity();
	glRotatef(camera.rotation.x, 1.0f, 0.0f, 0.0f);
	glRotatef(camera.rotation.y, 0.0f, 1.0f, 0.0f);
	glRotatef(camera.rotation.z, 0.0f, 0.0f, 1.0f);
	glTranslatef(-camera.position.x, -camera.position.y, -camera.position.z);

	//camera.position += camera.look * 0.1;

	/*
	gluLookAt(
			/////////////////////////////////////////////////////////////
			camera.position.x, camera.position.y, camera.position.z,
			/////////////////////////////////////////////////////////////
			camera.look.x * fabs((camera.position - camera.look).length),
		   	0,
			camera.look.z * fabs((camera.position - camera.look).length),
			/////////////////////////////////////////////////////////////
			0, 1, 0
			/////////////////////////////////////////////////////////////
			);

	*/
	glTranslatef(mesh.position.x, mesh.position.y, mesh.position.z);

	glRotatef(mesh.rotation.x, 1, 0, 0);
	glRotatef(mesh.rotation.y, 0, 1, 0);
	glRotatef(mesh.rotation.z, 0, 0, 1);

	glEnable(GL_LIGHTING);
	glBegin(GL_TRIANGLES);
		for (int i = 0; i < mesh.polygonCount; i++){
			glNormal3fv(mesh.vn[i].array);
			for (int j = 0; j < 3; j++){
				glVertex3fv(mesh.v[i][j].array);
			}
		}
	glEnd();
	for (int i = 0; i < 6; i++){
		glBegin(GL_LINE_LOOP);
		for (int j = 0; j < 4; j++){
			glVertex3fv(mesh.bounds[i].p[j].array);
		}
		glEnd();
	}
}

#endif
