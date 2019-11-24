#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "Vec3.h"
#include "print.h"


vec3** loadFromObj(const char * path, int& counter){
    FILE* object = NULL;
	object = fopen(path, "r");
    if(object == NULL){
        printf("File %s is not loaded\n", path);
    }
	float** temp_v = (float**)calloc(1, sizeof(float*));
	int** temp_f = (int**)calloc(1, sizeof(int*));
	float buf_v[3] = { 0 };
	int	buf_f[3] = { 0 };
	int	buf_fn[3] = { 0 };
	int v, f;
	v = f = 1;
	char lineHeader[128];
	int res;
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
				//// ADD buf_v in temp_v
				temp_v[v - 1] = (float*)calloc(3, sizeof(float));
				temp_v[v - 1][0] = buf_v[0];
				temp_v[v - 1][1] = buf_v[1];
				temp_v[v - 1][2] = buf_v[2];
				v++;
				temp_v = (float**)realloc(temp_v, sizeof(float*) * v);
			}
			else if (strcmp(lineHeader, "f") == 0)
			{
				fscanf(object, "%d/%d %d/%d %d/%d\n",
					&buf_f[0], &buf_fn[0],
					&buf_f[1], &buf_fn[1],
					&buf_f[2], &buf_fn[2]);
				// ADD buf_f in temp_f
				temp_f[f - 1] = (int*)calloc(3, sizeof(int));
				temp_f[f - 1][0] = buf_f[0];
				temp_f[f - 1][1] = buf_f[1];
				temp_f[f - 1][2] = buf_f[2];

				f++;
				temp_f = (int**)realloc(temp_f, sizeof(int*) * f);

			}

		}

	}
    vec3 ** ret = (vec3**)calloc((f - 1),sizeof(vec3 *));
    for (int i = 0; i < f - 1; i++)
    {
		ret[i] = (vec3*)calloc(3, sizeof(vec3));
		for (int j = 0; j < 3; j++)
		{
			ret[i][j].set(
				temp_v[temp_f[i][j]-1][0],
				temp_v[temp_f[i][j]-1][1],
				temp_v[temp_f[i][j]-1][2]);
		}
    }
	//deleting of buffers
	for(int i = 0; i < f - 1; i++){
		free(temp_f[i]);
	}
	for(int i = 0; i < v - 1; i++){
		free(temp_v[i]);
	}
	counter = (f - 1);
	return ret;
}
