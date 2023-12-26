#include <game_object.h>

game_object::game_object(SDL_Renderer *rend, int x, int y) : renderer_(rend),
					pos_x(x),
					pos_y(y),
					cur_clip(0),
					sprite_clips(),
					texture_(){}

game_object::~game_object() = default;

void game_object::render() {
  texture_.render(renderer_, pos_x, pos_y, &sprite_clips[cur_clip]);
}