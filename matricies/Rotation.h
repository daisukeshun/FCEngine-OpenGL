#pragma once
#include <malloc.h>
#include "MyMath.h"

float ** RotationX(float angle){
	float ** ret = (float**)calloc(4, sizeof(float*));
	int i;
	for(i = 0; i < 4; i++){
		ret[i] = (float*)calloc(4, sizeof(float));
	}
	ret[0][0] = 1;
	ret[1][1] = cosf(angle); ret[1][2] = -sinf(angle);
	ret[2][1] = sinf(angle); ret[2][2] = cosf(angle);
	ret[3][3] = 1;
	return ret;
}

float ** RotationY(float angle){
	float ** ret = (float**)calloc(4, sizeof(float*));
	int i;
	for(i = 0; i < 4; i++){
		ret[i] = (float*)calloc(4, sizeof(float));
	}
	ret[0][0] = cosf(angle);	ret[0][2] = sinf(angle);
	ret[1][1] = 1;
	ret[2][0] = -sinf(angle);	ret[2][2] = cosf(angle);
	ret[3][3] = 1;
	return ret;
}

float ** RotationZ(float angle){
	float ** ret = (float**)calloc(4, sizeof(float*));
	int i;
	for(i = 0; i < 4; i++){
		ret[i] = (float*)calloc(4, sizeof(float));
	}
	ret[0][0] = cosf(angle); ret[0][1] = -sinf(angle);
	ret[1][0] = sinf(angle); ret[1][1] = cosf(angle);
	ret[2][2] = 1;
	ret[3][3] = 1;
	return ret;
}

