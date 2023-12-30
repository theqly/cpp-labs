#include <plant.h>

plant::plant(SDL_Renderer *rend, int x, int y) : is_planted_(false), texture_(), timer_(), renderer_(rend), cur_clip(0), sprite_clips(){}

plant::~plant() = default;

void plant::plant_a_plant() {
  if(!is_planted_){
	is_planted_ = true;
	timer_.start();
  }
}

SDL_Rect plant::get_box() {
  return box;
}

void plant::update() {
  if(is_planted_) {
	if (timer_.get_time() > 3000) {
	  ++cur_clip;
	  if (cur_clip==4) is_planted_ = false;
	  timer_.reset();
	}
  }
}

bool plant::load_texture(const std::string &path) {
  texture_.load(path, renderer_);
  for(int i = 0; i < 5; ++i){
	sprite_clips[i].x = i*64;
	sprite_clips[i].y = 0;
	sprite_clips[i].w = 64;
	sprite_clips[i].h = 64;
  }
  for(int i = 5; i < 10; ++i){
	sprite_clips[i].x = (i-5)*64;
	sprite_clips[i].y = 64;
	sprite_clips[i].w = 64;
	sprite_clips[i].h = 64;
  }

  box.w = 64;
  box.h = 64;

  return true;
}

void plant::render() {
  texture_.render(renderer_, box.x, box.y, &sprite_clips[cur_clip]);
}