#pragma once
#ifndef INIT_H
#define INIT_H
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL2/SDL.h>
#include "print.h"
#include "Vec3.h"


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
			45.0f,
		   	(float) width / (float) height,
			0.1f, 10.0f);

	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);

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

	glPolygonMode(GL_BACK, GL_LINE);

	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
};
#endif
