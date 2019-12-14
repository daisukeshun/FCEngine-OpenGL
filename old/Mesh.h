#pragma once
#ifndef MESH_H
#define MESH_H
#include "Vec3.h"
#include "Collision.h"

class Mesh
{
private:
    char* path;
public:
    GLint polygonCount;
	vec3 pointMin;
	CollisionPlane * bounds;
	vec3 scale;
	vec3 pointMax;
    vec3 position;
    vec3 rotation;
	vec3 origin;
	vec3 originRotation;
    vec3** v;
    vec3 * vn;
    Mesh();
    Mesh(const char * file);
	void load(const char * file);
    char* getPath();
	void del();
};
#endif
