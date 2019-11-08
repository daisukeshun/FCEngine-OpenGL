#include "drawing.h"			//contain all drawing functions and macro
#include "types.h"				//contain custom types 
#include "objLoader.h"			//contain object loader function (old non-rewrite header file)
#include "settings.h"			//contain some global vars
#include <SDL2/SDL.h>			//drawing library
#include "init.h"

//macro for clearing renderer
//we chose black drawing color and clear renderer
#define clearRenderer(renderer)\
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);\
	SDL_RenderClear(renderer);

int main(int argc, char** argv){

	SDL_Window * window = init(WINDOW_WIDTH, WINDOW_HEIGHT);
							//our window
	SDL_Event event;			//sdl event (need for exit form drawing loop)

	Uint32 frameStart;			//need for calculating time of frames
	Uint32 frameTime;			//***********************************

	defMesh(rabbit);							//mesh definition 
	loadMesh(rabbit, "../Computer-Graphics-Labs/Lab5/Meshes/Rabbit_Lowpoly_1.obj");	//(wath more in mesh.h and objLoader.h

	//camera definition
	defCamera(camera);							//define Camera *
	isCamera(camera);							//create empty camera 
	defVec3f(buf);								//empty buffer for setting camera position and rotation
	setCamera(camera, 
			buf, buf,						//zero vectors
		   	0.0001f,						//near	surface for drawing/clipping
		   	1.f,							//far	surface for drawing/clipping
		   	120,							//angle of view (in degrees)
		   	WINDOW_WIDTH/WINDOW_HEIGHT);	//aspect ratio (4:3, 5:4, 16:9, 16:10, 21:9 etc.)


	delVec(buf);							//remove empty buffer
	setVec3(camera->rotation, 0, 0, 1);	//change camera rotation

	printf("Position\n");
	logVec3(rabbit->position);				//print mesh position in terminal

	setVec3(rabbit->position, 0, 0, 50);	//change mesh world position 
	setVec3(rabbit->rotation, 180, 0, 0);	//change meshes self rotation

	SDL_bool quit = SDL_FALSE;			//indicator for quit

	while (!quit){						
		frameStart = SDL_GetTicks();						//catch start time of drawing our frame
		display();

		frameTime = SDL_GetTicks() - frameStart;			//calculate time of frame
			SDL_GL_SwapWindow(window);
		//_______________________________ frame limiter ____________________________
		if (33 > frameTime){									
				SDL_Delay(33 - frameTime);
		}
		//__________________________________________________________________________

		//event puller (for quit press ESC btn or cross in terminal)
		while (SDL_PollEvent(&event)){
			if	(event.type == SDL_QUIT ||				//cross pressing
				 event.key.keysym.sym == SDLK_ESCAPE)	//ESC pressing
										{quit = SDL_TRUE;}

			switch (event.type)
			{
				case SDL_KEYDOWN:
					{
						switch(event.key.keysym.sym){
							case SDLK_w:
							break;
							case SDLK_s:
							break;
							case SDLK_a:
							break;
							case SDLK_d:
							break;
							case SDLK_UP:
							break;
							case SDLK_DOWN:
							break;
							case SDLK_LEFT:
							break;
							case SDLK_RIGHT:
							break;
						}
					}
				break;
			}
		}
	}

	//deleting camera
	//deleting all and destroy window
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
