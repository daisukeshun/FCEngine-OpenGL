#include "Camera.h"
#include <math.h>

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

GLfloat Camera::getLookDistance(){
	lookVector = look - position;
	return lookVector.length;
}

void Camera::rotate(GLfloat x, GLfloat y, GLfloat z){
	rotation.x = x;
	rotation.y = y;
	rotation.z = z;
	look.x = cosf(rotation.y);
	look.z = cosf(rotation.y);
}
