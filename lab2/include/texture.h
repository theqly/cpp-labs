#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <SDL.h>
#include <string>

class texture{
 public:
  texture();
  ~texture();

  void set_renderer(SDL_Renderer* ren);
  void load(const std::string& path);
  void clear();
  void apply_color();
  void render( int x, int y );

  int get_width() const;
  int get_height() const;

  Uint8 red = 255;
  Uint8 green = 255;
  Uint8 blue = 255;

 private:

  SDL_Renderer* renderer_;
  SDL_Texture* texture_;
  int width_;
  int height_;
};

#endif //TEXTURE_H_
