
#pragma once 
#include <malloc.h>
#include "FlatArray.c"
typedef struct Mesh{
	unsigned int polygonsCount;
	Vec3 position;
	Vec3 rotation;
	Vec3 axis;
	Vec3 axisRotation;
	Vec3 * normals;
	Vec3 scale;
	Triangle * polygons;
} Mesh;

void delMesh(Mesh m){
	free(m.polygons);
	free(m.normals);
}

Mesh * genMeshArray(GLint meshesCount){
	Mesh * ret = (Mesh *)calloc(meshesCount, sizeof(Mesh));
	int i;
	for(i = 0; i < meshesCount; i++){
		ret[i].scale = createVector(1.f, 1.f, 1.f);
		ret[i].position = createVector(0.f, 0.f, 0.f);
		ret[i].axis = createVector(0.f, 0.f, 0.f);
		ret[i].axisRotation = createVector(0.f, 0.f, 0.f);
		ret[i].polygonsCount = 0;
		ret[i].polygons = NULL;
		ret[i].normals = NULL;
	}
	return ret;
}


Mesh scaleMesh(Mesh mesh){
	unsigned int i, j;
	for(i = 0; i < mesh.polygonsCount; i++){
		for(j = 0; j < 3; j++){
			mesh.polygons[i].p[j] = mulVec3Vec3(mesh.polygons[i].p[j], mesh.scale);
		}
	}
	return mesh;
}

void delMeshes(Mesh * mesh, GLint meshesCount){
	int i;
	for(i = 0; i < meshesCount; i++){
		delMesh(mesh[i]);
	}
}

