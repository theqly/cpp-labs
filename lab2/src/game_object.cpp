#include <game_object.h>
#include <iostream>

game_object::game_object() : pos_x(0),
					pos_y(0),
					vel_x(0),
					vel_y(0),
					sprite_clips(),
					texture_(){}

game_object::~game_object() = default;

void game_object::init(SDL_Renderer *rend) {
  renderer_ = rend;
}

bool game_object::load_texture(const std::string& path){

  if(!texture_.load(path, renderer_)){
	std::cout << "game object cant load a texture with path" << path << std::endl;
	return false;
  }

  sprite_clips[0].x = 19;
  sprite_clips[0].y = 16;
  sprite_clips[0].w = 42;
  sprite_clips[0].h = 47;

  sprite_clips[1].x = 19;
  sprite_clips[1].y = 156;
  sprite_clips[1].w = 42;
  sprite_clips[1].h = 45;

  sprite_clips[2].x = 25;
  sprite_clips[2].y = 296;
  sprite_clips[2].w = 30;
  sprite_clips[2].h = 46;

  sprite_clips[3].x = 22;
  sprite_clips[3].y = 435;
  sprite_clips[3].w = 30;
  sprite_clips[3].h = 47;

  return true;
}

void game_object::handle_events(SDL_Event& e) {
  if(e.type == SDL_KEYDOWN && e.key.repeat == 0){
	switch (e.key.keysym.sym) {
	  case SDLK_w: vel_y -= 5; cur_clip = 1; break;
	  case SDLK_s: vel_y += 5; cur_clip = 0; break;
	  case SDLK_a: vel_x -= 5; cur_clip = 2; break;
	  case SDLK_d: vel_x += 5; cur_clip = 3; break;
	}
  }
  else if (e.type == SDL_KEYUP && e.key.repeat == 0){
	switch (e.key.keysym.sym) {
	  case SDLK_w: vel_y += 5; break;
	  case SDLK_s: vel_y -= 5; break;
	  case SDLK_a: vel_x += 5; break;
	  case SDLK_d: vel_x -= 5; break;
	}
  }
}

void game_object::move(){
  pos_x += vel_x;

  if(pos_x < 0 || pos_x + sprite_clips[cur_clip].w > 1280) pos_x -= vel_x;
  pos_y += vel_y;
  if(pos_y < 0 || pos_y + sprite_clips[cur_clip].h > 720) pos_y -= vel_y;
}

void game_object::render() {
  texture_.render(renderer_, pos_x, pos_y, &sprite_clips[cur_clip]);
}