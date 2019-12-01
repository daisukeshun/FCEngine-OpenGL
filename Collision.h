#pragma once
#ifndef COLLISION_H
#define COLLISION_H
#include "CollisionPlane.cpp"
#include "CollisionSphere.cpp"
#include <math.h>
#include "utils.h"
#include "print.h"


float centerDistance(
		const CollisionSphere& obj0, 
		const CollisionSphere& obj1)
{
	float x = obj0.center.x - obj1.center.x;
	float y = obj0.center.y - obj1.center.y;
	float z = obj0.center.z - obj1.center.z;
	return sqrt(x*x + y*y + z*z);
}

float centerDistance(
		const CollisionPlane& obj0, 
		const CollisionPlane& obj1)
{
	float x = obj0.center.x - obj1.center.x;
	float y = obj0.center.y - obj1.center.y;
	float z = obj0.center.z - obj1.center.z;
	return sqrt(x*x + y*y + z*z);
}

float distance(
	const CollisionSphere& obj0,
	const CollisionSphere& obj1)
{
	return (centerDistance(obj0, obj1) - (obj0.r + obj1.r));
}
float distance(
	const vec3& obj0,
	const vec3& obj1)
{
	float x = obj0.x - obj1.x;
	float y = obj0.y - obj1.y;
	float z = obj0.z - obj1.z;
	return sqrt(x*x + y*y + z*z);
}

float distance(
	const CollisionPlane& obj0,
	const CollisionPlane& obj1)
{
	return 0;
}

int AABB(
	const CollisionPlane& obj0,
	const CollisionPlane& obj1)
{
	if(	(obj0.p[0].x - obj1.p[0].x) <= obj0.width &&
		(obj0.p[0].y - obj1.p[0].y) <= obj0.height &&
		(obj0.p[0].z - obj1.p[0].z) <= obj0.depth){
		return 1;
	}else{
		return 0;
	}
}
#endif
