#pragma once
#include <malloc.h>
#include "MyMath.h"


float** Projection(const int WIDTH, const int HEIGHT, const float FOV, const float zNear, const float zFar){
	float ** projectionMatrix = NULL;
	projectionMatrix = (float**)calloc(4,sizeof(float*));
	int i = 0;
	for(i = 0; i < 4; i++){
		projectionMatrix[i] = (float*)calloc(4, sizeof(float));
	}

	float a = (float)WIDTH/(float)HEIGHT;
	float f = 1.0f/tanf(FOV * 0.5f / 180.0f * PI);
	float q = zFar / (zFar - zNear);

	projectionMatrix[0][0] = a*f;
	projectionMatrix[1][1] = f;
	projectionMatrix[2][2] = q;
	projectionMatrix[3][2] = -zNear*q;
	projectionMatrix[2][3] = 1.0f;
	projectionMatrix[3][3] = 0;

	return projectionMatrix;
}

Vec3 projectVec3(Vec3 a, float ** projectionMatrix){
	Vec3 ret = MultiplyMatrixVector(a, projectionMatrix);
	ret = divVec3(ret, ret.z);
	return ret;
}

Vec3 toCenterVec3(Vec3 a, const int WIDTH, const int HEIGHT){
	Vec3 ret = createVector(a.x, a.y, a.z);
	ret.x += 1.0f;
	ret.y += 1.0f;
	ret = createVector(ret.x * WIDTH/2, ret.y * HEIGHT/2, a.z);
	return ret;
}
