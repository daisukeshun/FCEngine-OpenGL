
#pragma once 
#include <malloc.h>
#include "FlatArray.c"
typedef struct Mesh{
	unsigned int polygonsCount;
	Vec3 position;
	Vec3 rotation;
	Vec3 axis;
	GLfloat axisRotation;
	Vec3 * normals;
	Triangle * polygons;
} Mesh;

void delMesh(Mesh m){
	free(m.polygons);
	free(m.normals);
}
