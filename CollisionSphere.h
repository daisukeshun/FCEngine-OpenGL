#pragma once
#ifndef COLLISION_SPHERE_H
#define COLLISION_SPHERE_H

#include "Vec3.h"

class CollisionSphere{
	public:
		GLfloat r;
		vec3 center;
		CollisionSphere();
		CollisionSphere(const vec3& vec, const GLfloat radius);
};

#endif
