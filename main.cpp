#include "Vec3.cpp"
#include "Mesh.cpp"
#include "Display.h"
#include "Init.h"

int main(int argc, char ** argv){

	int width = 600;
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
			SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN //| SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED
			);
	if(window == NULL)
		exit(1);
	SDL_GLContext glcontext = SDL_GL_CreateContext(window);

	Mesh mesh("./FinalBaseMesh.obj");
	mesh.position.set(0.5, -0.5, -4);
	print(mesh.position);

	SDL_Event event;
	SDL_bool quit = SDL_FALSE;
	
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	SDL_GetWindowSize(window, &width, &height);
	Init(width, height);
	float angle = 0;
	while(!quit){
		Display(mesh, angle);
		SDL_GL_SwapWindow(window);

		if(angle > 360)
			angle -= 359;
		if(state[SDL_SCANCODE_W]){
			mesh.position.z-=0.02;
		}
		if(state[SDL_SCANCODE_S]){
			mesh.position.z+=0.02;
		}
		if(state[SDL_SCANCODE_A]){
			mesh.position.x-=0.02;
		}
		if(state[SDL_SCANCODE_D]){
			mesh.position.x+=0.02;
		}
		if(state[SDL_SCANCODE_DOWN]){
			mesh.position.y-=0.02;
		}
		if(state[SDL_SCANCODE_UP]){
			mesh.position.y+=0.02;
		}
		if(state[SDL_SCANCODE_LEFT]){
			angle += 1;
		}
		if(state[SDL_SCANCODE_RIGHT]){
			angle -= 1;
		}
		SDL_PollEvent(&event);
		switch (event.type){
			case SDL_QUIT:
				quit = SDL_TRUE;
				break;
			case SDL_KEYDOWN:
				{
			switch (event.key.keysym.sym){
				case SDLK_ESCAPE:
					quit = SDL_TRUE;
				break;
				}
			}
			break;
		}
	}
	mesh.del();


	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
