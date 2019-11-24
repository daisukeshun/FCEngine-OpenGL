#include "CollisionSphere.h"


CollisionSphere::CollisionSphere(){
	r = 0;
	center.set();
}

CollisionSphere::CollisionSphere(const vec3& vec, const float radius){
	r = radius;
	center.set(vec.x, vec.y, vec.z);
}
