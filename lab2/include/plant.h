#ifndef PLANT_H_
#define PLANT_H_

#include <player.h>
#include <texture.h>
#include <timer.h>

class plant{
 public:
  plant(SDL_Renderer *rend, int x, int y);
  ~plant();
  void plant_a_plant(int type);
  bool check_collisions(SDL_Rect player);
  void handle_events(SDL_Event &e);
  bool load_texture(const std::string& path);
  void update(player& pl);
  void render();
 private:
  bool is_planted;
  bool is_player_in;
  SDL_Renderer* renderer_;

  char cur_clip;
  SDL_Rect sprite_clips[10];

  timer timer_;
  texture texture_;
  SDL_Rect box;
};

#endif //PLANT_H_