#pragma once
#include "graphics.h"
#include "mesh.h"
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

void drawTriangle(Triangle2i triangle){
	//clear buffers
	//-------------------------------------------------
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glFlush();
	//-------------------------------------------------
	
	//set lightning position
	//-------------------------------------------------
	float pos[] = { -2.0, 2.0, -3.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, pos); 
	//-------------------------------------------------

	//set color of triangle
	//-------------------------------------------------
	glColor3ub(0xff, 0xff, 0xff);
	//-------------------------------------------------
	
	//draw triangle by vertecies
	//-------------------------------------------------
	glBegin(GL_TRIANGLES);
		glVertex2i(	triangle[0][0],	 triangle[0][1]);
		glVertex2i(	triangle[1][0],	 triangle[1][1]);
		glVertex2i(	triangle[2][0],	 triangle[2][1]);
	glEnd();
	//-------------------------------------------------
}

void display(void){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glFlush();
	glLoadIdentity();				//back vector to basic positoin

	glTranslatef(0.0, 0.0, -1.0);
	glColor3ub(255, 255, 255);
	glTranslatef(0.0, 0.0, -2.5);

	glRotatef(45.0, 2.0, 10.0, 2.0);
	glBegin(GL_TRIANGLES);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(-0.5, 0.5, 0.0);
		glVertex3f(0.5, 0.5, 0.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, -0.5, 0.0);
		glVertex3f(0.5, -0.5, 0.0);
	glEnd();
}

