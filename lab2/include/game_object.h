#ifndef PERSON_H_
#define PERSON_H_

#include <texture.h>
#include <SDL.h>


class game_object{
 public:
  game_object();
  ~game_object();
  void init(SDL_Renderer* rend);
  bool load_texture(const std::string& path);
  void handle_events(SDL_Event& e);
  void move();
  void render();
 private:

  SDL_Renderer* renderer_;

  int pos_x, pos_y;
  int vel_x, vel_y;

  char cur_clip;
  SDL_Rect sprite_clips[4];
  texture texture_;
};

#endif //PERSON_H_
