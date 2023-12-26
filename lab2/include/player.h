#ifndef PLAYER_H_
#define PLAYER_H_
#include <texture.h>
#include <SDL.h>
#include <string>

class player{
 public:
  explicit player(SDL_Renderer* rend, int x = 0, int y = 0);
  void move();
  void handle_events(SDL_Event& e);
  bool load_texture(const std::string& path);
  void set_camera(SDL_Rect& camera);
  void render(SDL_Rect& camera);
 private:
  int vel_x, vel_y;

  char cur_clip;
  SDL_Rect sprite_clips[4];

  SDL_Renderer* renderer_;
  texture texture_;

  SDL_Rect collision_box;
};

#endif //PLAYER_H_
