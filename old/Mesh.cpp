#include "Mesh.h"
#include "ObjectLoader.cpp"
#include "utils.h"
#include <limits.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

template <typename T>
void swap(T a, T b){
    T buf = a;
    a = b;
    b = buf;
}

Mesh::Mesh(){
    path = (char*)calloc(1, sizeof(char));
}

void Mesh::load(const char * file){
	scale.set(1,1,1);
    unsigned int i = 0;
    path = (char*)calloc(1, sizeof(char));
    while (file[i] != '\0')
    {
        path[i] = file[i];
        i++;
        path = (char*)realloc(path, sizeof(char)*i);
        path[i] = 0;
    }

    v = loadFromObj(path, polygonCount);
    GLfloat len = 0;
    for (int i = 0; i < polygonCount; i++)
    {
        for (int j =  0; j < 3; j++)
        {
            len = max(len, v[i][j].length);
        }
        
    }
    vec3 v1;
    vec3 v2;
    vn = (vec3 *)calloc(polygonCount, sizeof(vec3));
	pointMax.set();
	pointMin.set(INT_MAX, INT_MAX, INT_MAX);
    for (int i = 0; i < polygonCount; i++)
    {
        v1 = v[i][0] - v[i][1];
        v2 = v[i][0] - v[i][2];
        vn[i] = v1.cross(v2);
        vn[i] /= len;
        vn[i].normalize();
        for (int j =  0; j < 3; j++)
        {
            v[i][j] /= len;

			pointMin.x = min(pointMin.x, v[i][j].x);
			pointMax.x = max(pointMax.x, v[i][j].x);

			pointMin.y = min(pointMin.y, v[i][j].y);
			pointMax.y = max(pointMax.y, v[i][j].y);

			pointMin.z = min(pointMin.z, v[i][j].z);
			pointMax.z = max(pointMax.z, v[i][j].z);
        }
    }

    bounds = (CollisionPlane*)calloc(6, sizeof(CollisionPlane));
	bounds[1].p[0].set(pointMin.x, pointMin.y, pointMin.z);
	bounds[1].p[1].set(pointMin.x, pointMax.y, pointMin.z);
	bounds[1].p[2].set(pointMin.x, pointMax.y, pointMax.z);
	bounds[1].p[3].set(pointMin.x, pointMin.y, pointMax.z);

	bounds[0].p[0].set(pointMin.x, pointMin.y, pointMin.z);
	bounds[0].p[1].set(pointMin.x, pointMin.y, pointMax.z);
	bounds[0].p[2].set(pointMax.x, pointMin.y, pointMax.z);
	bounds[0].p[3].set(pointMax.x, pointMin.y, pointMin.z);

	bounds[2].p[0].set(pointMin.x, pointMin.y, pointMin.z);
	bounds[2].p[1].set(pointMax.x, pointMin.y, pointMin.z);
	bounds[2].p[2].set(pointMax.x, pointMax.y, pointMin.z);
	bounds[2].p[3].set(pointMin.x, pointMax.y, pointMin.z);

	bounds[3].p[0].set(pointMax.x, pointMin.y, pointMin.z);
	bounds[3].p[1].set(pointMax.x, pointMin.y, pointMax.z);
	bounds[3].p[2].set(pointMax.x, pointMax.y, pointMax.z);
	bounds[3].p[3].set(pointMax.x, pointMax.y, pointMin.z);

	bounds[4].p[2].set(pointMax.x, pointMax.y, pointMax.z);
	bounds[4].p[3].set(pointMax.x, pointMax.y, pointMin.z);
	bounds[4].p[0].set(pointMin.x, pointMax.y, pointMin.z);
	bounds[4].p[1].set(pointMin.x, pointMax.y, pointMax.z);

	bounds[5].p[2].set(pointMax.x, pointMax.y, pointMax.z);
	bounds[5].p[3].set(pointMax.x, pointMin.y, pointMax.z);
	bounds[5].p[0].set(pointMin.x, pointMin.y, pointMax.z);
	bounds[5].p[1].set(pointMin.x, pointMax.y, pointMax.z);
}
Mesh::Mesh(const char * file){
	scale.set(1,1,1);
    unsigned int i = 0;
    path = (char*)calloc(1, sizeof(char));
    while (file[i] != '\0')
    {
        path[i] = file[i];
        i++;
        path = (char*)realloc(path, sizeof(char)*i);
        path[i] = 0;
    }

    v = loadFromObj(path, polygonCount);
    GLfloat len = 0;
    for (int i = 0; i < polygonCount; i++)
    {
        for (int j =  0; j < 3; j++)
        {
            len = max(len, v[i][j].length);
        }
        
    }
    vec3 v1;
    vec3 v2;
    vn = (vec3 *)calloc(polygonCount, sizeof(vec3));
	pointMax.set();
	pointMin.set(INT_MAX, INT_MAX, INT_MAX);
    for (int i = 0; i < polygonCount; i++)
    {
        v1 = v[i][0] - v[i][1];
        v2 = v[i][0] - v[i][2];
        vn[i] = v1.cross(v2);
        vn[i] /= len;
        vn[i].normalize();
        for (int j =  0; j < 3; j++)
        {
            v[i][j] /= len;

			pointMin.x = min(pointMin.x, v[i][j].x);
			pointMax.x = max(pointMax.x, v[i][j].x);

			pointMin.y = min(pointMin.y, v[i][j].y);
			pointMax.y = max(pointMax.y, v[i][j].y);

			pointMin.z = min(pointMin.z, v[i][j].z);
			pointMax.z = max(pointMax.z, v[i][j].z);
        }
    }

    bounds = (CollisionPlane*)calloc(6, sizeof(CollisionPlane));
	bounds[1].p[0].set(pointMin.x, pointMin.y, pointMin.z);
	bounds[1].p[1].set(pointMin.x, pointMax.y, pointMin.z);
	bounds[1].p[2].set(pointMin.x, pointMax.y, pointMax.z);
	bounds[1].p[3].set(pointMin.x, pointMin.y, pointMax.z);

	bounds[0].p[0].set(pointMin.x, pointMin.y, pointMin.z);
	bounds[0].p[1].set(pointMin.x, pointMin.y, pointMax.z);
	bounds[0].p[2].set(pointMax.x, pointMin.y, pointMax.z);
	bounds[0].p[3].set(pointMax.x, pointMin.y, pointMin.z);

	bounds[2].p[0].set(pointMin.x, pointMin.y, pointMin.z);
	bounds[2].p[1].set(pointMax.x, pointMin.y, pointMin.z);
	bounds[2].p[2].set(pointMax.x, pointMax.y, pointMin.z);
	bounds[2].p[3].set(pointMin.x, pointMax.y, pointMin.z);

	bounds[3].p[0].set(pointMax.x, pointMin.y, pointMin.z);
	bounds[3].p[1].set(pointMax.x, pointMin.y, pointMax.z);
	bounds[3].p[2].set(pointMax.x, pointMax.y, pointMax.z);
	bounds[3].p[3].set(pointMax.x, pointMax.y, pointMin.z);

	bounds[4].p[2].set(pointMax.x, pointMax.y, pointMax.z);
	bounds[4].p[3].set(pointMax.x, pointMax.y, pointMin.z);
	bounds[4].p[0].set(pointMin.x, pointMax.y, pointMin.z);
	bounds[4].p[1].set(pointMin.x, pointMax.y, pointMax.z);

	bounds[5].p[2].set(pointMax.x, pointMax.y, pointMax.z);
	bounds[5].p[3].set(pointMax.x, pointMin.y, pointMax.z);
	bounds[5].p[0].set(pointMin.x, pointMin.y, pointMax.z);
	bounds[5].p[1].set(pointMin.x, pointMax.y, pointMax.z);
}

char* Mesh::getPath(){
    return path;
}

void Mesh::del(){
	for(int i = 0; i < polygonCount; i++){
		free(this->v[i]);
		free(this->vn);
	}
	free(this->path);
	for(int i = 0; i < 6; i++){
		bounds[i].del();
	}
	free(this->bounds);
}
