#pragma once
#ifndef CAMERA_H
#define CAMERA_H
#include "Vec3.h"

class Camera{
	public:
		vec3 pos;
		vec3 look;
		vec3 rotation;
		Camera();
		Camera(vec3 pos);
		Camera(float x, float y, float z);
		Camera(float x, float y);
};

#endif
