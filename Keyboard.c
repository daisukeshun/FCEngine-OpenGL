#ifndef KEYBOARD_H
#define KEYBOARD_H
#include "Vec3.h"
unsigned char keys[258] = { 0 };
void keyDown(GLubyte key, GLint x, GLint y){
	keys[key] = 1;
	if(keys['f']){
		glutFullScreenToggle();
	}
}

void keyUp(GLubyte key, GLint x, GLint y){
	keys[key] = 0;
}
#endif
