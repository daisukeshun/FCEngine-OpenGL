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


	int meshesSize = 5;
	Mesh * meshes = (Mesh*)calloc(meshesSize, sizeof(Mesh));

	meshes[0].load("./FinalBaseMesh.obj");
	meshes[0].position.set(0, 0, -5);
	meshes[1].load("./deer.obj");
	meshes[1].position.set(0, 0, -4);
	meshes[2].load("./track_back.obj");
	meshes[2].position.set(1, -1, -2);

	SDL_Event event;
	SDL_bool quit = SDL_FALSE;
	
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	SDL_GetWindowSize(window, &width, &height);

	Init(120, width, height);

	Camera camera;
	camera.position.set(0, 0, 0);
	camera.rotation.set(0, 0, 0);
	while(!quit){
		Display(meshes, camera, meshesSize);
		SDL_GL_SwapWindow(window);

		if(state[SDL_SCANCODE_W]){
		}
		if(state[SDL_SCANCODE_S]){
		}
		if(state[SDL_SCANCODE_A]){
		}
		if(state[SDL_SCANCODE_D]){
		}
		if(state[SDL_SCANCODE_UP]){
			camera.position.x += sinf(camera.rotation.y / 180 * M_PI) * 0.1;
			camera.position.z -= cosf(camera.rotation.y / 180 * M_PI) * 0.1;
		}
		if(state[SDL_SCANCODE_DOWN]){
			camera.position.x -= sinf(camera.rotation.y / 180 * M_PI) * 0.1;
			camera.position.z += cosf(camera.rotation.y / 180 * M_PI) * 0.1;
		}
		if(state[SDL_SCANCODE_LEFT]){
			camera.rotation.y -= 2;
		}
		if(state[SDL_SCANCODE_RIGHT]){
			camera.rotation.y += 2;
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

	for(int i = 0; i < meshesSize; i++){
		meshes[i].del();
	}

	free(meshes);


	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
