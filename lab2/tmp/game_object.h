#ifndef PERSON_H_
#define PERSON_H_

#include <texture.h>
#include <SDL.h>


class game_object{
 public:
  explicit game_object(SDL_Renderer *rend, int x = 0, int y = 0);
  ~game_object();

  virtual bool load_texture(const std::string& path) = 0;
  virtual void handle_events(SDL_Event& e) = 0;
  virtual void render();
};

#endif //PERSON_H_
