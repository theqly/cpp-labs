#ifndef MENU_H_
#define MENU_H_


#include <button.h>
#include <texture.h>
#include <game_object.h>
#include <SDL.h>

#include <game.h>

class menu{
 public:
  menu();
  ~menu();
  void start();
 private:
  const size_t FPS = 60;
  const size_t frame_time = 1000 / FPS;

  bool is_running;
  bool is_game_started;

  void init();
  void loop();
  void keyboard_event();
  void update();
  void render();
  void run_game();
  void close();

  int screen_width_;
  int screen_height_;

  SDL_Window* window_;
  SDL_Renderer* renderer_;

  texture background_;

  int start_button_x;
  int start_button_y;
  button start_button_;

  game game_;
};


#endif //MENU_H_
