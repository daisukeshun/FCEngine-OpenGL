#include <stdio.h>
#include "MyMath.h"
#include <GL/freeglut.h>
#include "Init.c"
#include "Display.c"
#include "Reshape.c"
#include "Camera.h"

void timer();
void keyboard_f(GLubyte, GLint, GLint);

int main(int argc, char ** argv){
	int width, height;
	width = 200;
	height = 200;

	Init();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(300,300);
	glutInitWindowSize(width, height);
	glutCreateWindow("GLUT_WINDOW");


	glutKeyboardFunc(keyboard_f);
	glutDisplayFunc(display);

	gCam.speed.x = 0.1;
	gCam.speed.z = 0.1;

	Mesh m = loadMesh("./deer.obj");
	unsigned int i;
	int j;
	for(i = 0; i < m.polygonsCount; i++){
		for(j = 0; j < 3; j++){
			printf("%f %f %f\n", m.polygons->p[j].x, m.polygons->p[j].y, m.polygons->p[j].z);
		}
	}
	/*glutSpecialFunc(keyboard_f);*/
	delMesh(m);

	glutReshapeFunc(reshape);
	glutTimerFunc(0, timer, 0);

	glutMainLoop();
	return 0;
}


void timer(){
	glutTimerFunc(1000/60,timer, 0);
	ry += 2.f;
	/*rz += 0.2f;
	rx += 0.2f;
	gCam.rotation.y += 1;*/
	gCam.look.x = sin(toRadians(gCam.rotation.y));
	gCam.look.z = -cos(toRadians(gCam.rotation.z));

	glutPostRedisplay();
}

void keyboard_f(GLubyte key, GLint x, GLint y){
	switch(key){
		case 27:
			glutLeaveMainLoop();
			break;
		case 'w':
			gCam.position.x += gCam.look.x * gCam.speed.x;
			gCam.position.z += gCam.look.z * gCam.speed.z;
			break;
		case 's':
			gCam.position.x -= gCam.look.x * gCam.speed.x;
			gCam.position.z -= gCam.look.z * gCam.speed.z;
			break;
		case 'a':
			gCam.rotation.y-=2;
			break;
		case 'd':
			gCam.rotation.y+=2;
			break;
		case 'f':
			glutFullScreenToggle();
			break;
	}
}
