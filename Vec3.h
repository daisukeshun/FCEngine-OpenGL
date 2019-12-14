#pragma once
#include <math.h>
#include <GL/freeglut.h>

typedef struct Vec3{
	GLfloat x, y, z, w;
	GLint ix, iy;
	GLfloat length;
	GLfloat arrayForm[3];
} Vec3;

typedef Vec3 vec3;

Vec3 createVector(float x, float y, float z){
	Vec3 ret;
	ret.x = x;
	ret.y = y;
	ret.z = z;
	ret.ix = x;
	ret.iy = y;
	ret.w = 1;
	ret.arrayForm[0] = x;
	ret.arrayForm[1] = y;
	ret.arrayForm[2] = z;
	ret.length = sqrt(x*x + y*y + z*z);
	return ret;
};

Vec3 addVec3(Vec3 a, Vec3 b){
	return createVector(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vec3 subVec3(Vec3 a, Vec3 b){
	return createVector(a.x - b.x, a.y - b.y, a.z - b.z);
}

Vec3 mulVec3(Vec3 a, float num){
	return createVector(a.x*num, a.y*num, a.z*num);
}

Vec3 divVec3(Vec3 a, float num){
	return createVector(a.x/num, a.y/num, a.z/num);
}

Vec3 crossVec3(Vec3 a, Vec3 b){
	return createVector(
			a.y * b.z - a.z * b.y,
			a.x * b.z - a.z * b.x,
			a.x * b.y - a.y * b.x);
}

float dotVec3(Vec3 a, Vec3 b){
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

float lengthVec3(Vec3 a){
	a.length = sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
	return a.length;
}

