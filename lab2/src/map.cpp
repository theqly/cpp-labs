#include <map.h>
#include <fstream>

map::map(SDL_Renderer *rend, int screen_width, int screen_height) : renderer_(rend), tiles_(nullptr){}

map::~map() {
  delete[] tiles_;
}

void map::load(const std::string& path) {
  tiles_ = new tile[80*100];
  grass_.load("../assets/grass_1.bmp", renderer_);
  water_.load("../assets/Water.bmp", renderer_);
  std::ifstream map(path);
  int tile = -1;
  for(int i = 0; i < 80; ++i){
	for(int j = 0; j < 100; ++j){
	  map >> tile;
	  if(tile == 0){
		tiles_[i*80 + j].init(i*32, j*16, grass_);
	  }
	  else if(tile == 1){
		tiles_[i*80 + j].init(i*32, j*16, water_);
	  }
	}
  }
}

void map::render(SDL_Rect& camera) {
  for(int i = 0; i < 80; ++i){
	for(int j = 0; j < 100; ++j){
	  if(check_collisions(camera, tiles_[i*80 + j].get_box())){
		tiles_[i*80 + j].render(renderer_, camera);
	  }
	}
  }
}

bool map::check_collisions(SDL_Rect a, SDL_Rect b) {
  int leftA, leftB;
  int rightA, rightB;
  int topA, topB;
  int bottomA, bottomB;

  leftA = a.x;
  rightA = a.x + a.w;
  topA = a.y;
  bottomA = a.y + a.h;

  leftB = b.x;
  rightB = b.x + b.w;
  topB = b.y;
  bottomB = b.y + b.h;

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

bool map::touches_wall(SDL_Rect box) {
  for(int i = 0; i < 80; ++i){
	for(int j = 0; j < 100; ++j){
	  if (check_collisions(box, tiles_[i*80 + j].get_box())){
		return true;
	  }
	}
  }
  return false;
}

bool map::set_tiles() {
  return true;
}

tile::tile() : box_(){}

void tile::init(int x, int y, texture& tex) {
  box_.x = x;
  box_.y = y;
  box_.w = 32;
  box_.h = 16;
  texture_ = tex;
}

void tile::render(SDL_Renderer* rend, SDL_Rect &camera) {
  texture_.render(rend, box_.x - camera.x, box_.y - camera.y);
}

SDL_Rect tile::get_box() {
  return box_;
}