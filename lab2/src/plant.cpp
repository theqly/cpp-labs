#include <plant.h>

plant::plant(SDL_Renderer *rend, int x, int y) : is_planted(false), is_player_in(false), texture_(), timer_(), renderer_(rend), cur_clip(0), sprite_clips(){}

plant::~plant() = default;

void plant::plant_a_plant(int type) {
  if(!is_planted){
	is_planted = true;
	timer_.start();
  }
}

bool plant::check_collisions(SDL_Rect player) {
  int leftA, leftB;
  int rightA, rightB;
  int topA, topB;
  int bottomA, bottomB;

  leftA = player.x;
  rightA = player.x + player.w;
  topA = player.y;
  bottomA = player.y + player.h;

  leftB = box.x;
  rightB = box.x + box.w;
  topB = box.y;
  bottomB = box.y + box.h;

  if (bottomA <= topB){
	return false;
  }
  if (topA >= bottomB){
	return false;
  }
  if (rightA <= leftB){
	return false;
  }
  if (leftA >= rightB){
	return false;
  }

  return true;
}


void plant::update(player& pl) {
  if(check_collisions(pl.get_box())) is_player_in = true;
  else is_player_in = false;
  if(is_planted){
	/*switch (timer_.get_time()) {
	  case 10000: cur_clip = 0;
	  case 20000: cur_clip = 1;
	  case 30000: cur_clip = 2;
	  case 40000: cur_clip = 3;
	  case 50000: cur_clip = 4; timer_.stop();
	}*/
	uint32_t cur_time = timer_.get_time();
	if(cur_time > 2000 && cur_time < 4000) cur_clip = 1;
	else if(cur_time > 4000 && cur_time < 6000) cur_clip = 2;
	else if(cur_time > 8000 && cur_time < 10000) cur_clip = 3;
	else if(cur_time > 10000 && cur_time < 12000) cur_clip = 4; timer_.stop();
  }
  if(is_player_in) cur_clip += 5;
  if(cur_clip > 9) cur_clip %= 10;
}

void plant::handle_events(SDL_Event &e) {
  if(e.type == SDL_KEYDOWN && e.key.repeat == 0){
	if(is_player_in && e.key.keysym.sym == SDLK_e){
	  plant_a_plant(5);
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

  sprite_clips[0].x = 0;
  sprite_clips[0].y = 0;
  sprite_clips[0].w = 64;
  sprite_clips[0].h = 64;

  sprite_clips[1].x = 64;
  sprite_clips[1].y = 0;
  sprite_clips[1].w = 64;
  sprite_clips[1].h = 64;

  sprite_clips[2].x = 128;
  sprite_clips[2].y = 0;
  sprite_clips[2].w = 64;
  sprite_clips[2].h = 64;

  sprite_clips[3].x = 192;
  sprite_clips[3].y = 0;
  sprite_clips[3].w = 64;
  sprite_clips[3].h = 64;

  sprite_clips[4].x = 256;
  sprite_clips[4].y = 0;
  sprite_clips[4].w = 64;
  sprite_clips[4].h = 64;
  //---------------
  sprite_clips[5].x = 0;
  sprite_clips[5].y = 64;
  sprite_clips[5].w = 64;
  sprite_clips[5].h = 64;

  sprite_clips[6].x = 64;
  sprite_clips[6].y = 64;
  sprite_clips[6].w = 64;
  sprite_clips[6].h = 64;

  sprite_clips[7].x = 128;
  sprite_clips[7].y = 64;
  sprite_clips[7].w = 64;
  sprite_clips[7].h = 64;

  sprite_clips[8].x = 192;
  sprite_clips[8].y = 64;
  sprite_clips[8].w = 64;
  sprite_clips[8].h = 64;

  sprite_clips[9].x = 256;
  sprite_clips[9].y = 64;
  sprite_clips[9].w = 64;
  sprite_clips[9].h = 64;

  box.w = 64;
  box.h = 64;

  return true;
}

void plant::render() {
  texture_.render(renderer_, box.x, box.y, &sprite_clips[cur_clip]);
}