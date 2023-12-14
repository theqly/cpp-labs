#include <texture.h>

#include <SDL_image.h>

texture::texture() : renderer_(nullptr), texture_(nullptr), width_(0), height_(0){}

texture::~texture() {
  clear();
}

void texture::set_renderer(SDL_Renderer *ren) {
  renderer_ = ren;
}

void texture::load(const std::string& path) {
  clear();
  SDL_Surface* loaded = IMG_Load(path.c_str());
  SDL_SetColorKey(loaded, SDL_TRUE, SDL_MapRGB(loaded->format, 0, 0xFF, 0xFF));
  SDL_Texture* tmp = SDL_CreateTextureFromSurface(renderer_, loaded);
  width_ = loaded->w;
  height_ = loaded->h;
  texture_ = tmp;
}

void texture::clear() {
  if(texture_ != nullptr){
	SDL_DestroyTexture(texture_);
	texture_ = nullptr;
	width_ = 0;
	height_ = 0;
  }
}

void texture::apply_color() {
  SDL_SetTextureColorMod(texture_, red, green, blue);
}

void texture::render(int x, int y) {
  SDL_Rect render_quad = { x, y, width_, height_};
  SDL_RenderCopy(renderer_, texture_, nullptr, &render_quad);
}

int texture::get_width() const {
  return width_;
}

int texture::get_height() const {
  return height_;
}

