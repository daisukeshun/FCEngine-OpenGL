#include "Triangle.h"
#include <malloc.h>

GLfloat * toFlatArrayTriangle(Triangle * triangles, int count){
	GLfloat * ret = NULL;
	ret = (GLfloat*)calloc(1, sizeof(GLfloat));
	int i, j, k;
	k = 0;
	for (i = 0; i < count; i++){
		for(j = 0; j < 3; j++){
			k+=3;
			ret = (GLfloat*)realloc(ret, sizeof(GLfloat)*k);
			ret[k-3] = triangles[i].p[j].x;
			ret[k-2] = triangles[i].p[j].y;
			ret[k-1] = triangles[i].p[j].z;
		}
	}
	return ret;
}

