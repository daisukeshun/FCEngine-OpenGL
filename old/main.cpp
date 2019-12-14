#include "Vec3.cpp"
#include "Mesh.cpp"
#include "Camera.cpp"
#include "Display.h"
#include "Init.h"

int main(int argc, char ** argv){

	int width = 1280;
	int height = 720;
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
			SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE 
			);
	if(window == NULL)
		exit(1);
	SDL_GLContext glcontext = SDL_GL_CreateContext(window);

	int meshes_in_track = 5;
	Mesh * track = (Mesh*)calloc(meshes_in_track, sizeof(Mesh));

	track[0].load("./wheels1.obj");
	track[0].position.set(0, 0, -1);
	track[1].load("./wheels1.obj");
	track[1].position.set(0, 0, -3);
	track[2].load("./wheels1.obj");
	track[2].position.set(0, 0, -11);

	track[3].load("./track_back.obj");
	track[3].position.set(0, 0, -2);
	track[3].scale.set(11, 11, 11);

	track[4].load("./track_body.obj");
	track[4].scale.set(3, 3, 3);
	track[4].position.set(0, 0, -2);

	SDL_Event event;
	SDL_bool quit = SDL_FALSE;
	
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	SDL_GetWindowSize(window, &width, &height);

	Init(45, width, height);

	Camera camera;
	camera.position.set(0, 0, 0);
	camera.rotation.set(0, 0, 0);

	track[3].origin.set(0,1,2);
	track[3].originRotation.set(0,0,90);
	GLfloat speed = 0.1;
	while(!quit){
		Display(track, camera, meshes_in_track);
		SDL_GL_SwapWindow(window);

		if(state[SDL_SCANCODE_W]){
			for(int i = 0; i < 3; i++){
				track[i].rotation.x += 2;
			}
		}
		if(state[SDL_SCANCODE_S]){
			for(int i = 0; i < 3; i++){
				track[i].rotation.x -= 2;
			}
		}
		if(state[SDL_SCANCODE_A]){
			if(track[3].rotation.y != 50){
				track[3].rotation.y += 1;
			}
		}
		if(state[SDL_SCANCODE_D]){
			if(track[3].rotation.y != -50){
				track[3].rotation.y -= 1;
			}
		}
		if(state[SDL_SCANCODE_UP]){
			camera.position.x += sinf(camera.rotation.y / 180 * M_PI) * speed;
			camera.position.z -= cosf(camera.rotation.y / 180 * M_PI) * speed;
		}
		if(state[SDL_SCANCODE_DOWN]){
			camera.position.x -= sinf(camera.rotation.y / 180 * M_PI) * speed;
			camera.position.z += cosf(camera.rotation.y / 180 * M_PI) * speed;
		}
		if(state[SDL_SCANCODE_LEFT]){
			camera.rotation.y -= 2;
		}
		if(state[SDL_SCANCODE_RIGHT]){
			camera.rotation.y += 2;
		}
		if(state[SDL_SCANCODE_LSHIFT]){
			speed = 0.5;
		}
		if(state[SDL_SCANCODE_LCTRL]){
			speed = 0.05;
		}
		if(state[SDL_SCANCODE_H]){
			track[3].origin.x++;
			track[3].origin.z--;
		}
		if(state[SDL_SCANCODE_L]){
			track[3].origin.z++;
			track[3].origin.x--;
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

	for(int i = 0; i < meshes_in_track; i++){
		track[i].del();
	}
	for(int i = 0; i < 3; i++){
		track[i].del();
	}
	free(track);


	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
