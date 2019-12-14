#pragma once
#ifndef CAMERA_H
#define CAMERA_H
#include "Vec3.h"

typedef struct {
	vec3 position;
	vec3 look;
	vec3 rotation;
	vec3 speed;
} Camera;

#endif
