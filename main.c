#include <stdio.h>
#include "MyMath.h"
#include <GL/freeglut.h>
#include "Init.c"
#include "Display.c"
#include "Reshape.c"
#include "Camera.h"
#include "Keyboard.c"

void timer();

int main(int argc, char ** argv){ int width, height;
	width = 200;
	height = 200;

	Init();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glutInitWindowPosition(300,300);
	glutInitWindowSize(width, height);
	glutCreateWindow("GLUT_WINDOW");

	gCam.speed.x = 0.1;
	gCam.speed.z = 0.1;
	gCam.look = createVector(0.f, 0.f, -1.f);

	mesh = (Mesh *)calloc(meshesCount, sizeof(Mesh));
	mesh[0] = loadMesh("./pyramidca.obj");
	mesh[0].position = createVector(0.f, 0.f, -1.f);

	mesh[1] = loadMesh("./pyramidca.obj");
	mesh[1].position = createVector(2.f, 0.f, -1.f);
	mesh[1].rotation = createVector(0.f, 80.f, 0.f);
	mesh[1].axis = createVector(1.f, 0.f, 1.f);

	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
	glutKeyboardFunc(keyDown);
	glutKeyboardUpFunc(keyUp);

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutTimerFunc(0, timer, 0);

	glutMainLoop();

	int i;
	for(i = 0; i < meshesCount; i++){
		delMesh(mesh[i]);
	}
	return 0;
}


void timer(){
	glutTimerFunc(1000/60,timer, 0);

	if(keys[27]){
		glutLeaveMainLoop();
	}
	if(keys['w']){
		gCam.position.x += gCam.look.x * gCam.speed.x;
		gCam.position.z += gCam.look.z * gCam.speed.z;
	}
	if(keys['s']){
		gCam.position.x -= gCam.look.x * gCam.speed.x;
		gCam.position.z -= gCam.look.z * gCam.speed.z;
	}
	if(keys['a']){
		gCam.rotation.y-=2;
	}
	if(keys['d']){
		gCam.rotation.y+=2;
	}
	if(keys['z']){
		mesh[1].axisRotation++;
		mesh[1].rotation.y++;
	}

	gCam.look.x = sin(toRadians(gCam.rotation.y));
	gCam.look.z = -cos(toRadians(gCam.rotation.y));

	glutPostRedisplay();
}

