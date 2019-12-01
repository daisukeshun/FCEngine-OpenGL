#pragma once
#ifndef COLLISION_SPHERE_H
#define COLLISION_SPHERE_H

#include "Vec3.h"

class CollisionSphere{
	public:
		float r;
		vec3 center;
		CollisionSphere();
		CollisionSphere(const vec3& vec, const float radius);
};

#endif
