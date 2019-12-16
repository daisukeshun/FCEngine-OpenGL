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
	int id = glutCreateWindow("GLUT_WINDOW");

	gCam.speed.x = 0.05;
	gCam.speed.z = 0.05;
	gCam.look = createVector(0.f, 0.f, 1.f);

	mesh = genMeshArray(meshesCount);
	mesh[0] = loadMesh("./track_back.obj");
	mesh[0].position = createVector(0.f, 0.f, 2.f);
	mesh[0].axis = createVector(0.f, 0.f, 5.f);

	mesh[5] = loadMesh("./track_body.obj");
	mesh[5].position = createVector(0.f, 0.2f, 10.f);
	mesh[5].axis = createVector(0.f, 0.f, 0.f);

	mesh[1] = loadMesh("./wheel.obj");
	mesh[1].position = createVector(1.f, 0.f, 0.f);
	mesh[1].axis = createVector(0.f, 0.f, 5.f);

	mesh[2] = loadMesh("./wheel.obj");
	mesh[2].position = createVector(-1.f, 0.f, 0.f);
	mesh[2].axis = createVector(0.f, 0.f, 5.f);

	mesh[3] = loadMesh("./wheel.obj");
	mesh[3].position = createVector(-1.f, 0.f, -15.f);
	mesh[3].axis = createVector(0.f, 0.f, 5.f);

	mesh[4] = loadMesh("./wheel.obj");
	mesh[4].position = createVector(1.f, 0.f, -15.f);
	mesh[4].axis = createVector(0.f, 0.f, 5.f);

	int i;
	for(i = 1; i < 5; i++){
		mesh[i].position.y = -0.5f;
	}
	mesh[6] = loadMesh("./wheel.obj");
	mesh[6].position = createVector(1.f, -0.5f, 8.5f);

	mesh[7] = loadMesh("./wheel.obj");
	mesh[7].position = createVector(-1.f, -0.5f, 8.5f);


	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
	glutKeyboardFunc(keyDown);
	glutKeyboardUpFunc(keyUp);

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutTimerFunc(0, timer, 0);

	glutMainLoop();

	delMeshes(mesh, meshesCount);
	glutDestroyWindow(id);
	return 0;
}


void timer(){
	glutTimerFunc(1000/60,timer, 0);

	int i;
	for(i = 1; i < 5; i++)
		mesh[i].rotation.x+=5;
	for(i = 6; i < 8; i++)
		mesh[i].rotation.x+=5;

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
		int i;
		for(i = 0; i < 5; i++){
			if(mesh[i].axisRotation.y < 30.f)
				mesh[i].axisRotation.y++;
		}
	}
	if(keys['x']){
		int i;
		for(i = 0; i < 5; i++){
			if(mesh[i].axisRotation.y > -30.f)
				mesh[i].axisRotation.y--;
		}
	}

	gCam.look.x = sin(toRadians(gCam.rotation.y));
	gCam.look.z = -cos(toRadians(gCam.rotation.y));

	glutPostRedisplay();
}

