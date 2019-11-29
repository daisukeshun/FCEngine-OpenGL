#include "Camera.h"

Camera::Camera(){
	pos.set();
	look.set();
	rotation.set();
}
Camera::Camera(vec3 pos){
	this->pos += pos;
	look.set();
	rotation.set();
}
Camera::Camera(float x, float y, float z){
	pos.set(x, y, z);
	look.set();
	rotation.set();
}

Camera::Camera(float x, float y){
	pos.set(x, y, 0);
	look.set();
	rotation.set();
}
