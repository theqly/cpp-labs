#include <map.h>

map::map(SDL_Renderer *rend, int screen_width, int screen_height) : renderer_(rend){
  tiles_ = new Tile[80*100];
}

void map::load(const std::string& path) {
  grass_.load("../assets/grass_1.bmp", renderer_);
  water_.load("../assets/Water.bmp", renderer_);
  for(int i = 0; i < 80; ++i){
	for(int j = 0; j < 100; ++j){
	  tiles_[i*80 + j].init(i*32, j*16, grass_);
	}
  }
}

void map::render(SDL_Rect& camera) {
  for(int i = 0; i < 80; ++i){
	for(int j = 0; j < 100; ++j){
	  if(check_collisions(camera, tiles_[i].getBox())){
		tiles_[i].render(renderer_, camera);
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
	  if (check_collisions(box, tiles_[i].getBox())){
		return true;
	  }
	}
  }
  return false;
}

bool map::set_tiles() {

}

Tile::Tile() : mBox(){}

void Tile::init(int x, int y, texture& tex) {

  mBox.x = x;
  mBox.y = y;
  mBox.w = 32;
  mBox.h = 16;
  texture_ = tex;
}

void Tile::render(SDL_Renderer* rend, SDL_Rect &camera) {
  texture_.render(rend, mBox.x - camera.x, mBox.y - camera.y);
}

SDL_Rect Tile::getBox() {
  return mBox;
}