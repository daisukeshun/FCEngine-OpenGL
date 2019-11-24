#include "Vec3.cpp"
#include "Mesh.cpp"
#include "Display.h"
#include "Init.h"

int main(int argc, char ** argv){

	int width = 800;
	int height = 600;
	switch (argc)
	{
		case 3:
			{
				width = atoi(argv[1]);
				height = atoi(argv[2]);
			}
		break;
	}

	SDL_Window * window = SDL_CreateWindow(
			argv[0],
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			width, height,
			SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED
			);
	if(window == NULL)
		exit(1);
	SDL_GLContext glcontext = SDL_GL_CreateContext(window);

	Mesh mesh("./deer.obj");

	SDL_Event event;
	SDL_bool quit = SDL_FALSE;
	
	SDL_GetWindowSize(window, &width, &height);
	Init(width, height);
	float angle = 0;
	while(!quit){
		if(angle < 360)
			angle += 1;
		else
			angle -= 359;
		SDL_PollEvent(&event);

		switch (event.type){
			case SDL_QUIT:
				quit = SDL_TRUE;
				break;
			case SDL_WINDOWEVENT_RESIZED:
				gluPerspective(45, 
					(float)width/(float)height,
					0.1, 100.0
				);
				break;
			case SDL_KEYDOWN:
				{
					switch (event.key.keysym.sym){
						case SDLK_ESCAPE:
							quit = SDL_TRUE;
							break;
						case SDLK_a:
							angle+=1.0;
							break;
						case SDLK_d:
							angle-=1.0;
							break;
					}
				}
				break;
		}
		Display(mesh, angle);
		glFlush();
		SDL_GL_SwapWindow(window);
	}


	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}