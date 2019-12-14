#pragma once
#include "Vec3.h"
#include <malloc.h>
float ** TranslationVec(Vec3 traslateVector){
	float ** ret = (float**)calloc(4, sizeof(float*));
	int i;
	for(i = 0; i < 4; i++){
		ret[i] = (float*)calloc(4, sizeof(float));
		ret[i][i] = 1;
	}
	ret[3][0] = traslateVector.x;
	ret[3][1] = traslateVector.y;
	ret[3][2] = traslateVector.z;
	return ret;
}

float ** Translationfv(float* traslateVector){
	float ** ret = (float**)calloc(4, sizeof(float*));
	int i;
	for(i = 0; i < 4; i++){
		ret[i] = (float*)calloc(4, sizeof(float));
		ret[i][i] = 1;
	}
	ret[3][0] = traslateVector[0];
	ret[3][1] = traslateVector[1];
	ret[3][2] = traslateVector[2];
	return ret;
}

float ** Translationf(float x, float y, float z){
	float ** ret = (float**)calloc(4, sizeof(float*));
	int i;
	for(i = 0; i < 4; i++){
		ret[i] = (float*)calloc(4, sizeof(float));
		ret[i][i] = 1;
	}
	ret[3][0] = x;
	ret[3][1] = y;
	ret[3][2] = z;
	return ret;
}
