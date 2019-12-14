#pragma once
#include <stdio.h>
#include "Vec3.h"

void print(const vec3 v){
	printf("%f %f %f\n", v.x, v.y, v.z);
}
void print(const vec3 * arr, const int count){
	for(int i = 0; i < count; i++){
		print(arr[i]);
	}
	printf("\n");
}
void print(const float num){
	printf("%f\n",num);
}
void print(const float * arr, const int count){
	for(int i = 0; i < count; i++){
		printf("%f ", arr[i]);
	}
	printf("\n");
}
void print(const int * arr, const int count){
	for(int i = 0; i < count; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void print(const int num){
	printf("%d\n", num);
}

void print(const unsigned int num){
	printf("%d\n", num);
}
void print(const char * string){
	printf("%s\n", string);
}

void print(const char ** string, const int count){
	for(int i = 0; i < count; i++){
		printf("%s\n", string[i]);
	}
}
