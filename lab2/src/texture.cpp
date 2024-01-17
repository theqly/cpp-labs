#include <texture.h>
#include <iostream>
#include <SDL_image.h>

texture::texture() : texture_(nullptr), width_(0), height_(0) {}

texture::~texture() {
	clear();
}

bool texture::load(const std::string &path, SDL_Renderer *rend) {
	clear();
	SDL_Surface *loaded = IMG_Load(path.c_str());
	if (!loaded) {
		std::cout << "cant open a image with path" << path << std::endl;
		return false;
	}
	SDL_SetColorKey(loaded, SDL_TRUE, SDL_MapRGB(loaded->format, 0, 0xFF, 0xFF));
	SDL_Texture *tmp = SDL_CreateTextureFromSurface(rend, loaded);
	width_ = loaded->w;
	height_ = loaded->h;
	texture_ = tmp;
	free(loaded);
	return true;
}

void texture::clear() {
	if (texture_!=nullptr) {
		SDL_DestroyTexture(texture_);
		texture_ = nullptr;
		width_ = 0;
		height_ = 0;
	}
}

void texture::set_color(Uint8 red, Uint8 green, Uint8 blue) {
	SDL_SetTextureColorMod(texture_, red, green, blue);
}

void texture::set_blendmode(SDL_BlendMode blending) {
	SDL_SetTextureBlendMode(texture_, blending);
}

void texture::set_alpha(Uint8 alpha) {
	SDL_SetTextureAlphaMod(texture_, alpha);
}

void texture::render(SDL_Renderer *rend,
					 int x,
					 int y,
					 SDL_Rect *clip,
					 double angle,
					 SDL_Point *center,
					 SDL_RendererFlip flip) {
	SDL_Rect render_quad = {x, y, width_, height_};
	if (clip!=nullptr) {
		render_quad.w = clip->w;
		render_quad.h = clip->h;
	}
	SDL_RenderCopyEx(rend, texture_, clip, &render_quad, angle, center, flip);
}

int texture::get_width() const {
	return width_;
}

int texture::get_height() const {
	return height_;
}

