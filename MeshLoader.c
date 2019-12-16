#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Mesh.h"
Mesh loadMesh(const char* path)
{
	FILE* object = NULL;
	object = fopen(path, "r");
	if(object == NULL){
		printf("ERROR!!!! \n");
		printf("can't load file %s\n", path);
		printf("ERROR!!!! \n");
		exit(1);
	}

	GLfloat** temp_v = (GLfloat**)calloc(1, sizeof(GLfloat*));
	GLint** temp_f = (GLint**)calloc(1, sizeof(GLint*));
	GLfloat buf_v[3] = { 0 };
	GLint	buf_f[3] = { 0 };
	GLint	buf_fn[3] = { 0 };
	GLint v, f;
	v = f = 1;
	char lineHeader[128];
	GLint res;
	char slashCounter = -1;
	char strWithSlashes[128];
	long int pos = -1;
	int i, j;
	while (1)
	{
		res = fscanf(object, "%s", lineHeader);
		if (res == EOF)
		{
			break;
		}
		else
		{
			if (strcmp(lineHeader, "v") == 0)
			{

				fscanf(object, "%f %f %f\n", &buf_v[0], &buf_v[1], &buf_v[2]);
				temp_v[v - 1] = (GLfloat*)calloc(3, sizeof(GLfloat));
				temp_v[v - 1][0] = buf_v[0];
				temp_v[v - 1][1] = buf_v[1];
				temp_v[v - 1][2] = buf_v[2];
				v++;
				temp_v = (GLfloat**)realloc(temp_v, sizeof(GLfloat*) * v);
			}
			else if (strcmp(lineHeader, "f") == 0)
			{
				if(slashCounter < 0){
					pos = ftell(object);
					slashCounter = 0;
					fscanf(object, "%s", strWithSlashes);
					fseek(object, pos, SEEK_SET);
					for(i = 0; i < 128; i++){
						if(strWithSlashes[i] == '/'){
						slashCounter++;
						}
					}
				}
				switch(slashCounter){
					case 0:
				fscanf(object, "%d %d %d\n",
					&buf_f[0],
					&buf_f[1],
					&buf_f[2]);
						break;
					case 1:
				fscanf(object, "%d/%d %d/%d %d/%d\n",
					&buf_f[0], &buf_fn[0],
					&buf_f[1], &buf_fn[1],
					&buf_f[2], &buf_fn[2]);
						break;
					case 2:
				fscanf(object, "%d//%d %d//%d %d//%d\n",
					&buf_f[0], &buf_fn[0],
					&buf_f[1], &buf_fn[1],
					&buf_f[2], &buf_fn[2]);
						break;
				}
				temp_f[f - 1] = (int*)calloc(3, sizeof(int));
				temp_f[f - 1][0] = buf_f[0];
				temp_f[f - 1][1] = buf_f[1];
				temp_f[f - 1][2] = buf_f[2];

				f++;
				temp_f = (int**)realloc(temp_f, sizeof(int*) * f);

			}

		}

	}

	Mesh ret;
	ret.polygonsCount = f - 1;
	ret.polygons = (Triangle*)calloc(ret.polygonsCount, sizeof(Triangle));

	printf("%d\n", ret.polygonsCount);
	for (i = 0; i < f - 1; i++)
	{
		for(j = 0; j < 3; j++){
			ret.polygons[i].p[j] = createVector(
					temp_v[temp_f[i][j]-1][0],
					temp_v[temp_f[i][j]-1][1],
					temp_v[temp_f[i][j]-1][2]);
		}
	}
	printf("model was loaded:%s\n", path);

	/*
	for (i = 0; i < f - 1; i++)
	{
		for(j = 0; j < 3; j++){
			ret.polygons[i].p[j] = divVec3(ret.polygons[i].p[j], len);
		}
	}
	*/
	for(i = 0; i < (f - 1); i++){
		free(temp_f[i]);
	}
	for(i = 0; i < (v - 1); i++){
		free(temp_v[i]);
	}
	fclose(object);
	return ret;
}
