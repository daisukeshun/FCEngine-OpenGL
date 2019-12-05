#include "Vec3.cpp"
#include "Mesh.cpp"
#include "Camera.cpp"
#include "Display.h"
#include "Init.h"

int main(int argc, char ** argv){

	int width = 800;
	int height = 800;
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
	mesh.position.set(0, 0, -2);

	SDL_Event event;
	SDL_bool quit = SDL_FALSE;
	
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	SDL_GetWindowSize(window, &width, &height);

	Init(width, height);

	Camera camera;
	camera.position.set(0, 0, 0);
	camera.look.set(0.0, 0, 1.0);
	while(!quit){
		Display(mesh, camera);
		SDL_GL_SwapWindow(window);

		if(state[SDL_SCANCODE_W]){
			mesh.position.z += 0.1;
		}
		if(state[SDL_SCANCODE_S]){
			mesh.position.z -= 0.1;
		}
		if(state[SDL_SCANCODE_A]){
			mesh.rotation.y -= 1;
		}
		if(state[SDL_SCANCODE_D]){
			mesh.rotation.y += 1;
		}
		if(state[SDL_SCANCODE_DOWN]){
		}
		if(state[SDL_SCANCODE_UP]){
		}
		if(state[SDL_SCANCODE_LEFT]){
			camera.look.x -= 0.02;
		}
		if(state[SDL_SCANCODE_RIGHT]){
			camera.look.x += 0.02;
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
