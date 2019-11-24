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
		float nx, float ny, float nz,
		float p0x, float p0y, float p0z,
		float p1x, float p1y, float p1z,
		float p2x, float p2y, float p2z,
		float p3x, float p3y, float p3z)
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
	p[0].set((float)p0x, (float)p0y, (float)p0z);
	p[1].set((float)p1x, (float)p1y, (float)p1z);
	p[2].set((float)p2x, (float)p2y, (float)p2z);
	p[3].set((float)p3x, (float)p3y, (float)p3z);
	normal.set((float)nx, (float)ny, (float)nz);

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
