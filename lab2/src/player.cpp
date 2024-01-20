#include <player.h>
#include <iostream>

player::player(SDL_Renderer *rend, int x, int y)
	: renderer_(rend), vel_x(0), vel_y(0), cur_clip(0), sprite_clips(), texture_() {
	collision_box.x = x;
	collision_box.y = y;
}

player::~player() = default;

void player::move() {
	collision_box.x += vel_x;
	if (collision_box.x < 0 || collision_box.x + sprite_clips[cur_clip].w >= 2560) collision_box.x -= vel_x;
	collision_box.y += vel_y;
	if (collision_box.y < 0 || collision_box.y + sprite_clips[cur_clip].h >= 1600) collision_box.y -= vel_y;
}

SDL_Rect player::get_box() {
	return collision_box;
}

void player::handle_events(SDL_Event &e) {
	if (e.type==SDL_KEYDOWN && e.key.repeat==0) {
		switch (e.key.keysym.sym) {
			case SDLK_w: vel_y -= 10;
				cur_clip = 1;
				break;
			case SDLK_s: vel_y += 10;
				cur_clip = 0;
				break;
			case SDLK_a: vel_x -= 10;
				cur_clip = 2;
				break;
			case SDLK_d: vel_x += 10;
				cur_clip = 3;
				break;
		}
	} else if (e.type==SDL_KEYUP && e.key.repeat==0) {
		switch (e.key.keysym.sym) {
			case SDLK_w: vel_y += 10;
				break;
			case SDLK_s: vel_y -= 10;
				break;
			case SDLK_a: vel_x += 10;
				break;
			case SDLK_d: vel_x -= 10;
				break;
		}
	}
}

bool player::load_texture(const std::string &path) {

	texture_.load(path, renderer_);

	sprite_clips[0].x = 19;
	sprite_clips[0].y = 16;
	sprite_clips[0].w = 42;
	sprite_clips[0].h = 47;

	sprite_clips[1].x = 19;
	sprite_clips[1].y = 156;
	sprite_clips[1].w = 42;
	sprite_clips[1].h = 47;

	sprite_clips[2].x = 25;
	sprite_clips[2].y = 296;
	sprite_clips[2].w = 42;
	sprite_clips[2].h = 47;

	sprite_clips[3].x = 22;
	sprite_clips[3].y = 435;
	sprite_clips[3].w = 42;
	sprite_clips[3].h = 47;

	return true;
}

void player::set_camera(SDL_Rect &camera) {
	camera.x = (collision_box.x + sprite_clips[cur_clip].w/2) - 1920/2;
	camera.y = (collision_box.y + sprite_clips[cur_clip].h/2) - 1080/2;
	if (camera.x < 0) camera.x = 0;
	if (camera.y < 0) camera.y = 0;
	if (camera.x > 2560 - camera.w) camera.x = 2560 - camera.w;
	if (camera.y > 1600 - camera.h) camera.y = 1600 - camera.h;
}

void player::render(SDL_Rect &camera) {
	texture_.render(renderer_, collision_box.x - camera.x, collision_box.y - camera.y, &sprite_clips[cur_clip]);
}