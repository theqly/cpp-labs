#ifndef GAME_H_
#define GAME_H_

#include <texture.h>
#include <SDL.h>

class game{
 public:
  game();
  ~game();
  void run();
 private:
  const size_t FPS = 60;
  const size_t frame_time = 1000 / FPS;

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
  texture start_button_;
};

#endif //GAME_H_
