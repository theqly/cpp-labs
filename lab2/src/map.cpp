#include <map.h>
#include <fstream>

map::map(SDL_Renderer *rend) : width_in_tiles(100), height_in_tiles(80), renderer_(rend), tiles_(nullptr), beet_(rend, 0, 0){}

map::~map() {
  delete[] tiles_;
}

void map::load(const std::string& path) {
  tiles_ = new tile[width_in_tiles * height_in_tiles];
  beet_.load_texture("../assets/beet.bmp");
  grass_.load("../assets/grass.bmp", renderer_);
  water_.load("../assets/water.bmp", renderer_);
  std::ifstream map(path);
  int tile = -1;
  for(int i = 0; i < height_in_tiles; ++i){
	for(int j = 0; j < width_in_tiles; ++j){
	  map >> tile;
	  if(tile == 0){
		tiles_[i*height_in_tiles + j].init(i*grass_.get_width(), j*grass_.get_height(), grass_);
	  }
	  else if(tile == 1){
		tiles_[i*height_in_tiles + j].init(i*water_.get_width(), j*water_.get_height(), water_);
	  }
	}
  }
}

void map::handle_events(SDL_Event &e, player& pl) {
  if(e.type == SDL_KEYDOWN && e.key.repeat == 0){
	if(check_collisions(pl.get_box(), beet_.get_box()) && e.key.keysym.sym == SDLK_f){
	  beet_.plant_a_plant();
	}
  }
}

void map::update() {
  beet_.update();
}

void map::render(SDL_Rect& camera) {
  for(int i = 0; i < height_in_tiles; ++i){
	for(int j = 0; j < width_in_tiles; ++j){
	  if(check_collisions(camera, tiles_[i*height_in_tiles + j].get_box())){
		tiles_[i*height_in_tiles + j].render(renderer_, camera);
		if(check_collisions(tiles_[i*height_in_tiles + j].get_box(), beet_.get_box())) beet_.render();
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