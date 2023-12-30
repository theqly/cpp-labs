#ifndef PLANT_H_
#define PLANT_H_

#include <player.h>
#include <texture.h>
#include <timer.h>

class plant{
 public:
  plant(SDL_Renderer *rend, int x, int y);
  ~plant();
  bool load_texture(const std::string& path);
  void update();
  void render();
  void plant_a_plant();
  SDL_Rect get_box();
 private:
  bool is_planted_;

  SDL_Renderer* renderer_;

  char cur_clip;
  SDL_Rect sprite_clips[10];

  timer timer_;
  texture texture_;
  SDL_Rect box;
};

#endif //PLANT_H_