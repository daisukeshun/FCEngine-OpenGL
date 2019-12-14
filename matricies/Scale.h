#pragma once
#include <malloc.h>
#include "MyMath.h"

float ** ScaleVec(Vec3 traslateVector){
	float ** ret = (float**)calloc(4, sizeof(float*));
	int i;
	for(i = 0; i < 4; i++){
		ret[i] = (float*)calloc(4, sizeof(float));
		ret[i][i] = 1;
	}
	ret[0][0] = traslateVector.x;
	ret[1][1] = traslateVector.y;
	ret[2][2] = traslateVector.z;
	return ret;
}

float ** Scalefv(float* traslateVector){
	float ** ret = (float**)calloc(4, sizeof(float*));
	int i;
	for(i = 0; i < 4; i++){
		ret[i] = (float*)calloc(4, sizeof(float));
		ret[i][i] = 1;
	}
	ret[0][0] = traslateVector[0];
	ret[1][1] = traslateVector[1];
	ret[2][2] = traslateVector[2];
	return ret;
}

float ** Scalef(float x, float y, float z){
	float ** ret = (float**)calloc(4, sizeof(float*));
	int i;
	for(i = 0; i < 4; i++){
		ret[i] = (float*)calloc(4, sizeof(float));
		ret[i][i] = 1;
	}
	ret[0][0] = x;
	ret[1][1] = y;
	ret[2][2] = z;
	return ret;
}
