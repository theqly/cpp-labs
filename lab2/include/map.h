#ifndef MAP_H_
#define MAP_H_

#include <texture.h>
#include <SDL.h>

class Tile
{
 public:
  Tile();
  void init(int x, int y, texture& tex);
  SDL_Rect getBox();
  void render(SDL_Renderer* rend, SDL_Rect &camera);
 private:
  texture texture_;
  SDL_Rect mBox;
};

class map{
 public:

  map(SDL_Renderer* rend, int screen_width, int screen_height);
  void load(const std::string& path);
  void render(SDL_Rect& camera);
  bool check_collisions(SDL_Rect a, SDL_Rect b);
  bool touches_wall(SDL_Rect box);
  bool set_tiles();
 private:
  SDL_Renderer* renderer_;
  texture grass_;
  texture water_;

  Tile* tiles_;
};



#endif //MAP_H_
