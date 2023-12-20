#ifndef BUTTON_H_
#define BUTTON_H_

#include <texture.h>
#include <functional>
#include <SDL.h>

enum button_clip{
  BUTTON_SPRITE_MOUSE_OUT = 0,
  BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
  BUTTON_SPRITE_MOUSE_DOWN = 2,
  BUTTON_SPRITE_MOUSE_UP = 3
};

class button{
 public:
  button(int x = 0, int y = 0);
  ~button();
  void load();
  void set_renderer(SDL_Renderer* rend);
  void set_position(int x, int y);
  void handle_events(SDL_Event* e);

  void render();

 private:
  SDL_Point position_;
  button_clip current_clip_;
  texture texture_;
  SDL_Rect clips[4];
};

#endif //BUTTON_H_
