#include "CollisionPlane.h"
#include <math.h>

CollisionPlane::CollisionPlane(){
	p[0].set(0, 0, 0);
	p[1].set(0, 1, 0);
	p[2].set(1, 0, 0);
	p[3].set(1, 1, 0);
	normal.set(0, 0, 1);

	for(int i = 0; i < 4; i++){
		if(p[0].x != p[i].x){
			width = abs(p[i].x - p[0].x);
			center.x = (p[i].x - p[0].x) / 2;
		}
		if(p[0].x != p[i].x)
		{
			height = abs(p[i].y - p[0].y);
			center.y = (p[i].y - p[0].y) / 2;
		}
		if(p[0].x != p[i].x)
		{
			depth = abs(p[i].z - p[0].z);
			center.z = (p[i].z - p[0].z) / 2;
		}
	}

}

CollisionPlane::CollisionPlane(
		GLfloat nx, GLfloat ny, GLfloat nz,
		GLfloat p0x, GLfloat p0y, GLfloat p0z,
		GLfloat p1x, GLfloat p1y, GLfloat p1z,
		GLfloat p2x, GLfloat p2y, GLfloat p2z,
		GLfloat p3x, GLfloat p3y, GLfloat p3z)
{
	p[0].set(p0x, p0y, p0z);
	p[1].set(p1x, p1y, p1z);
	p[2].set(p2x, p2y, p2z);
	p[3].set(p3x, p3y, p3z);
	normal.set(nx, ny, nz);

	for(int i = 0; i < 4; i++){
		if(p[0].x != p[i].x){
			width = abs(p[i].x - p[0].x);
			center.x = (p[i].x - p[0].x) / 2;
		}
		if(p[0].x != p[i].x)
		{
			height = abs(p[i].y - p[0].y);
			center.y = (p[i].y - p[0].y) / 2;
		}
		if(p[0].x != p[i].x)
		{
			depth = abs(p[i].z - p[0].z);
			center.z = (p[i].z - p[0].z) / 2;
		}
	}
}

CollisionPlane::CollisionPlane(
		double nx, double ny, double nz,
		double p0x, double p0y, double p0z,
		double p1x, double p1y, double p1z,
		double p2x, double p2y, double p2z,
		double p3x, double p3y, double p3z)
{
	p[0].set((GLfloat)p0x, (GLfloat)p0y, (GLfloat)p0z);
	p[1].set((GLfloat)p1x, (GLfloat)p1y, (GLfloat)p1z);
	p[2].set((GLfloat)p2x, (GLfloat)p2y, (GLfloat)p2z);
	p[3].set((GLfloat)p3x, (GLfloat)p3y, (GLfloat)p3z);
	normal.set((GLfloat)nx, (GLfloat)ny, (GLfloat)nz);

	for(int i = 0; i < 4; i++){
		if(p[0].x != p[i].x){
			width = abs(p[i].x - p[0].x);
			center.x = (p[i].x - p[0].x) / 2;
		}
		if(p[0].x != p[i].x)
		{
			height = abs(p[i].y - p[0].y);
			center.y = (p[i].y - p[0].y) / 2;
		}
		if(p[0].x != p[i].x)
		{
			depth = abs(p[i].z - p[0].z);
			center.z = (p[i].z - p[0].z) / 2;
		}
	}
}
CollisionPlane::CollisionPlane(
		const vec3& n,
		const vec3& p0,
		const vec3& p1,
		const vec3& p2,
		const vec3& p3)
{
	p[0]+=p0;
	p[1]+=p1;
	p[2]+=p2;
	p[3]+=p3;
	normal+=n;

	for(int i = 0; i < 4; i++){
		if(p[0].x != p[i].x){
			width = abs(p[i].x - p[0].x);
			center.x = (p[i].x - p[0].x) / 2;
		}
		if(p[0].x != p[i].x)
		{
			height = abs(p[i].y - p[0].y);
			center.y = (p[i].y - p[0].y) / 2;
		}
		if(p[0].x != p[i].x)
		{
			depth = abs(p[i].z - p[0].z);
			center.z = (p[i].z - p[0].z) / 2;
		}
	}
}

void CollisionPlane::del(){
	free(this->p);
}
