#include <bed.h>

bed::bed(SDL_Renderer *rend, int pos_x, int pos_y) : renderer_(rend), cur_plant(renderer_){
	box.x = pos_x;
	box.y = pos_y;
	texture_.load("..assets/bed.bmp", renderer_);
}