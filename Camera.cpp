#include "Camera.h"

Camera::Camera(){
	position.set();
	look.set();
	lookVector = position - look;
	rotation.set();
}
Camera::Camera(vec3 position){
	this->position += position;
	look.set();
	lookVector = position - look;
	rotation.set();
}
Camera::Camera(GLfloat x, GLfloat y, GLfloat z){
	position.set(x, y, z);
	look.set();
	lookVector = position - look;
	rotation.set();
}

Camera::Camera(GLfloat x, GLfloat y){
	position.set(x, y, 0);
	look.set();
	lookVector = position - look;
	rotation.set();
}

void Camera::moveTo(GLfloat speed){
	lookVector = look - position;
	lookVector += lookVector * speed;
}

vec3 Camera::getLookDistance(){
	lookVector = look - position;
	return lookVector;
}
