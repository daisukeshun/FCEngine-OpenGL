#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

SDL_Window * init(int width, int height){

	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		printf("SDL not initialized!\n");
		exit(1);
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); //enable double buffering
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE,	8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,	8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,	8);
	//SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,	8);
	
	SDL_GLContext glcontext;
	
	//define sdl window
	SDL_Window * window = SDL_CreateWindow("FCENGINE",				//name of window
		   	SDL_WINDOWPOS_CENTERED,					//window position X
		   	SDL_WINDOWPOS_CENTERED,					//window position Y
			width,									//window width
		   	height,									//window height
			SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);	//window rendering settings

	if(window == NULL){
		exit(1);
	}

	//opengl initialization
	glcontext = SDL_GL_CreateContext(window);			//create context of OpenGL
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				//clearing color of context
	glClearDepth(1.0);									//
	glDepthFunc(GL_LESS);								//
	glShadeModel(GL_SMOOTH);							//
	glMatrixMode(GL_PROJECTION);						//enable projection matrix mode
	glLoadIdentity();

	//_________________________ settings for 3d perspective ______________________________
	gluPerspective(
			45.0f,											//fov
			(float) width / (float) height,					//aspect ratio
			0.1f,											//zNear	
			100.0f);										//zFar
	//_____________________ end of settings for 3d perspective ___________________________

	glMatrixMode(GL_MODELVIEW);				//enable 3d view

	//enabling
	glEnable(GL_DEPTH_TEST);							//enable depth test
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	float dif[] = {1.0, 1.0, 1.0, 1.0};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);
	float amb[] = {0.2, 0.2, 0.2, 0.2};
	glLightfv(GL_LIGHT0, GL_AMBIENT, amb);



	return window;
}
