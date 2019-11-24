#ifndef COLLISION_PLANE_H
#define COLLISION_PLANE_H

#include "Vec3.h"

class CollisionPlane{

	public:
		vec3 p[4];
		vec3 normal;
		vec3 center;
		float width;
		float height;
		float depth;
		CollisionPlane(
				float nx, float ny, float nz,
				float p0x, float p0y, float p0z,
				float p1x, float p1y, float p1z,
				float p2x, float p2y, float p2z,
				float p3x, float p3y, float p3z);

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

};

#endif
