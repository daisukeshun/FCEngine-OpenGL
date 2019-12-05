#pragma once
#ifndef INIT_H
#define INIT_H
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL2/SDL.h>
#include "print.h"
#include "Vec3.h"

/*
class GLInit{
	private:
		GLint redAttr = 8, greenAttr = 8, blueAttr = 8, doubleBufferAttrib = 1;
		vec3 clearColor;
		GLfloat zNear = 0.1, zFar = 10.0;
		GLfloat clearDepth = 0;
		GLint width, height, FOV;
		GLfloat diffusion[4] = {1, 1, 1, 1};
		GLfloat ambient[4] = {0.2, 0.2, 0.2, 0.2};
		GLfloat position[4] = {0, 0, -0.1, 0.1};
	public:
		GLInit(GLint width, GLint height);
		void attrib(char state);
		void clear(char state);
		void perspective(char state);
		void depth(char state);
		void light(char state);

};

GLInit::GLInit(GLint width, GLint height){
	this->height = height;
	this->width = width;
	print("GLinit init");
}

void GLInit::attrib(char state){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(state){
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, doubleBufferAttrib);
		SDL_GL_SetAttribute(SDL_GL_RED_SIZE, redAttr);
		SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, greenAttr);
		SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, blueAttr);
		print("attributes was setted");
	} else {
		SDL_GL_ResetAttributes();
	}
}

void GLInit::clear(char state){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(state){
		glClearColor(clearColor.x, clearColor.y, clearColor.z, 1.0);
		glClearDepth(clearDepth);
		print("cleaning was init");
	}else{
		glClearColor(clearColor.x, clearColor.y, clearColor.z, 0.0);
		glClearDepth(0);
	}
}

void GLInit::perspective(char state){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(state){
		gluPerspective(
			FOV,
		   	(GLfloat) width / (GLfloat) height, 
			zNear, zFar); 
		print("perspective was init");
	}else{
		gluPerspective( 0, 0, 0, 0); 
	}
}

void GLInit::depth(char state){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if(state){
		glEnable(GL_DEPTH_TEST);
		print("depth test was init");
	}else{
		glDisable(GL_DEPTH_TEST);
	}
}

void GLInit::light(char state){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if(state){
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, diffusion);
		glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
		glLightfv(GL_LIGHT0, GL_POSITION, position);
		print("light was init");
	}else{
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT0);
	}
}
*/


static void Init(
		const unsigned short width,
		const unsigned short height)
{
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(
			45,
		   	(float) width / (float) height,
			0.1f, 10.0f);

	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	float diffusion[] = {1, 1, 1, 1};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffusion);

	float ambient[] = {0.2, 0.2, 0.2, 0.2};
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
};

static void Init(
		float FOV,
		const unsigned short width,
		const unsigned short height)
{
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(
			FOV,
		   	(float) width / (float) height,
			0.1f, 1000.0f);

	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	float diffusion[] = {1, 1, 1, 1};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffusion);

	float ambient[] = {0.2, 0.2, 0.2, 0.2};
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

};
#endif
