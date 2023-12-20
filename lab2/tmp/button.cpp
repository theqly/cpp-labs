#include <button.h>

const int BUTTON_WIDTH = 320;
const int BUTTON_HEIGHT = 180;

button::button(int x, int y){
  position_.x = x;
  position_.y = y;
  current_clip_ = BUTTON_SPRITE_MOUSE_OUT;
}

button::~button() = default;

void button::load() {
  //texture_.load("../assets/start_button.jpg");
  for(int i = 0; i < 4; ++i){
	clips[i].x = 0;
	clips[i].y = i * 180;
	clips[i].w = BUTTON_WIDTH;
	clips[i].h = BUTTON_HEIGHT;
  }
}


void button::set_position(int x, int y) {
  position_.x = x;
  position_.y = y;
}

void button::handle_events(SDL_Event *e) {
  if(e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP){
	int x, y;
	SDL_GetMouseState(&x, &y);
	bool inside = true;
	if(x < position_.x) inside = false;
	else if(x > position_.x + BUTTON_WIDTH) inside = false;
	else if(y < position_.y) inside = false;
	else if(y > position_.y + BUTTON_HEIGHT) inside = false;
	if(!inside) current_clip_ = BUTTON_SPRITE_MOUSE_OUT;
	else{
	  switch (e->type) {
		case SDL_MOUSEMOTION:
		  current_clip_ = BUTTON_SPRITE_MOUSE_OVER_MOTION;
		  break;
		case SDL_MOUSEBUTTONDOWN:
		  current_clip_ = BUTTON_SPRITE_MOUSE_DOWN;
		  break;
		case SDL_MOUSEBUTTONUP:
		  current_clip_ = BUTTON_SPRITE_MOUSE_UP;
		  break;
	  }
	}
  }
}

void button::render() {
  texture_.render(position_.x, position_.y, &clips[current_clip_]);
}