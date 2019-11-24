#ifndef MESH_H
#define MESH_H
#include "Vec3.h"
class Mesh
{
private:
    char* path;
public:
    int polygonCount;
    vec3 position;
    vec3 rotation;
    vec3** v;
    vec3 * vn;
    void sortPolygons();
    Mesh();
    Mesh(const char * file);
    char* getPath();
};
#endif