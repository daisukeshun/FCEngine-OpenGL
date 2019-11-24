#include "Mesh.h"
#include "ObjectLoader.cpp"
#include "utils.h"
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

void Mesh::sortPolygons(){
    for (int i = 0; i < polygonCount; i++)
    {
        if(v[i][0].x < v[i][1].x){
           swap(v[i][0], v[i][1]);
        } 
        if(v[i][1].x < v[i][2].x){
           swap(v[i][1], v[i][2]);
        }
        if(v[i][1].x < v[i][2].x){
           swap(v[i][1], v[i][2]);
        }
    }
    
}

Mesh::Mesh(const char * file){
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
    float len = 0;
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
        }
    }
    

}

char* Mesh::getPath(){
    return path;
}
