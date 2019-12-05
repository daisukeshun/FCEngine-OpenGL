#pragma once
#ifndef CAMERA_H
#define CAMERA_H
#include "Vec3.h"

class Camera{
	public:
		vec3 position;
		vec3 look;
		vec3 rotation;
		vec3 lookVector;
		Camera();
		Camera(vec3 position);
		Camera(GLfloat x, float y, float z);
		Camera(GLfloat x, float y);
		void moveTo(GLfloat speed);
		vec3 getLookDistance();
};

#endif
