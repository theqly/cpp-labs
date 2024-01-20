#ifndef BED_H_
#define BED_H_

#include <texture.h>
#include <plant.h>
#include <SDL.h>

class bed{
  public:
	bed(SDL_Renderer* rend, int pos_x, int pos_y);
  private:
	SDL_Renderer* renderer_;
	SDL_Rect box;
	texture texture_;

	plant cur_plant;
};

#endif //BED_H_
