#ifndef GAME_H_
#define GAME_H_

#include <texture.h>
#include <game_object.h>
#include <timer.h>
#include <SDL.h>

class game{
 public:
  game();
  ~game();
  void run();
 private:
  uint32_t fps = 60;
  uint32_t frame_time = 1000 / fps;

  timer fps_timer;
  timer cap_timer;

  bool is_running;

  void init();
  void gameloop();
  void keyboard_event();
  void update();
  void render();
  void close();

  int screen_width_;
  int screen_height_;

  SDL_Window* window_;
  SDL_Renderer* renderer_;

  texture background_;

  game_object character;
};

#endif //GAME_H_
