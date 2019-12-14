#pragma once
#ifndef COLLISION_PLANE_H
#define COLLISION_PLANE_H

#include "Vec3.h"

class CollisionPlane{

	public:
		vec3 p[4];
		vec3 normal;
		vec3 center;
		GLfloat width;
		GLfloat height;
		GLfloat depth;
		CollisionPlane(
				GLfloat nx, GLfloat ny, GLfloat nz,
				GLfloat p0x, GLfloat p0y, GLfloat p0z,
				GLfloat p1x, GLfloat p1y, GLfloat p1z,
				GLfloat p2x, GLfloat p2y, GLfloat p2z,
				GLfloat p3x, GLfloat p3y, GLfloat p3z);

		CollisionPlane(
				double nx, double ny, double nz,
				double p0x, double p0y, double p0z,
				double p1x, double p1y, double p1z,
				double p2x, double p2y, double p2z,
				double p3x, double p3y, double p3z);

		CollisionPlane(
				const vec3& normal,
				const vec3& p1,
				const vec3& p2,
				const vec3& p3,
				const vec3& p4);

		CollisionPlane();
		void del();

};

#endif
