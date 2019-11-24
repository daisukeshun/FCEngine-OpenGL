#include "Vec3.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

vec3::vec3(){
	x=y=z=0;
	w=1;
	length=0;
}

vec3::vec3(float a, float b){
	x = a;
	y = b;
	z = 0;
	length = sqrt(x*x + y*y + z*z);
}
vec3::vec3(float a, float b, float c){
	x = a;
	y = b;
	z = c;
	length = sqrt(x*x + y*y + z*z);
}

float vec3::dot(const vec3& vec){
	return (x*vec.x + y*vec.y + z*vec.z);
}

vec3 vec3::cross(const vec3& vec){
	return vec3(
			y*vec.z - z*vec.y,
			x*vec.z - z*vec.x,
			x*vec.y - y*vec.x
			);
}

vec3 vec3::cross(const vec3& a, const vec3& b){
	return vec3(
			a.y*b.z - a.z*b.y,
			a.x*b.z - a.z*b.x,
			a.x*b.y - a.y*b.x
			);
}
void vec3::normalize(){
	x /= length;
	y /= length;
	z /= length;
	w = length;
}

void vec3::set(){
	x=y=z=0;
	w=1;
	length=0;
}
void vec3::set(float a, float b){
	x = a;
	y = b;
	z = 0;
	length = sqrt(x*x + y*y + z*z);
}
void vec3::set(float a, float b, float c){
	x = a;
	y = b;
	z = c;
	length = sqrt(x*x + y*y + z*z);
}

vec3 vec3::operator+(const vec3& vec){
	return vec3(x+vec.x, y+vec.y, z+vec.z);
}
vec3 vec3::operator-(const vec3& vec){
	return vec3(x-vec.x, y-vec.y, z-vec.z);
}

vec3 vec3::operator*(const float num){
	return vec3(x*num, y*num, z*num);
}

vec3 vec3::operator/(const float num){
	return vec3(x/num, y/num, z/num);
}


vec3 vec3::operator+=(const vec3& vec){
	x+=vec.x;
   	y+=vec.y;
   	z+=vec.z;
	length = sqrt(x*x + y*y + z*z);
	return *this;
}

vec3 vec3::operator-=(const vec3& vec){
	x-=vec.x;
   	y-=vec.y;
   	z-=vec.z;
	length = sqrt(x*x + y*y + z*z);
	return *this;
}

vec3 vec3::operator*=(const float num){
	x*=num;
   	y*=num;
   	z*=num;
	length = sqrt(x*x + y*y + z*z);
	return *this;
}

vec3 vec3::operator/=(const float num){
	if(num != 0){
		x/=num;
		y/=num;
		z/=num;
		length = sqrt(x*x + y*y + z*z);
	}else{
		fprintf(stderr, "Division by zero!");
		exit(1);
	}
	return *this;
}


bool vec3::operator==(const vec3& vec){
	return (x==vec.x && y==vec.y && z==vec.z);
}
bool vec3::operator!=(const vec3& vec){
	return !(x==vec.x && y==vec.y && z==vec.z);
}

