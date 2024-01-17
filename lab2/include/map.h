#ifndef MAP_H_
#define MAP_H_

#include <texture.h>
#include <plant.h>
#include <SDL.h>

class tile {
  public:
	tile();
	void init(int x, int y, texture &tex);
	SDL_Rect get_box();
	void render(SDL_Renderer *rend, SDL_Rect &camera);
  private:
	texture texture_;
	SDL_Rect box_;
};

class map {
  public:
	map(SDL_Renderer *rend);
	~map();
	void load(const std::string &path);
	void handle_events(SDL_Event &e, player &pl);
	void update();
	void render(SDL_Rect &camera);
	bool check_collisions(SDL_Rect a, SDL_Rect b);
  private:
	int width_in_tiles;
	int height_in_tiles;

	SDL_Renderer *renderer_;
	texture grass_;
	texture water_;

	tile *tiles_;

	plant beet_;
};

#endif //MAP_H_
