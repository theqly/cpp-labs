#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <SDL.h>
#include <string>

class texture {
  public:
	texture();
	~texture();

	bool load(const std::string &path, SDL_Renderer *rend);
	void clear();
	void set_color(Uint8 red, Uint8 green, Uint8 blue);
	void set_blendmode(SDL_BlendMode blending);
	void set_alpha(Uint8 alpha);
	void render(SDL_Renderer *rend,
				int x,
				int y,
				SDL_Rect *clip = nullptr,
				double angle = 0.0,
				SDL_Point *center = nullptr,
				SDL_RendererFlip flip = SDL_FLIP_NONE);

	int get_width() const;
	int get_height() const;

  private:
	SDL_Texture *texture_;
	int width_;
	int height_;
};

#endif //TEXTURE_H_
