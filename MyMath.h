#pragma once
#include "Vec3.h"
#define PI 3.14159f

Vec3 MultiplyMatrixVector(Vec3 a, float ** b){
	Vec3 ret = createVector(
			a.x * b[0][0] + a.y * b[1][0] + a.z * b[2][0] + b[3][0],
			a.x * b[0][1] + a.y * b[1][1] + a.z * b[2][1] + b[3][1],
			a.x * b[0][2] + a.y * b[1][2] + a.z * b[2][2] + b[3][2]
			);
	float w = a.x * b[0][3] + a.y * b[1][3] + a.z * b[2][3] + b[3][3];
	if(w != 0){
		a.x /= w;
		a.y /= w;
	}
	return ret;
}

GLfloat toRadians(GLfloat a){
	return (GLfloat)(a * PI / 180.f);
}
