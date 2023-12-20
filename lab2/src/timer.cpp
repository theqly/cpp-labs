#include <timer.h>
#include <SDL.h>

timer::timer() : start_time(0), paused_time(0), is_started(false), is_paused(false) {}

void timer::start() {
  is_started = true;
  is_paused = false;
  start_time = SDL_GetTicks();
  paused_time = 0;
}

void timer::stop() {
  is_started = false;
  is_paused = false;
  start_time = 0;
  paused_time = 0;
}

void timer::pause() {
  if(is_started && !is_paused){
	is_paused = true;
	paused_time = SDL_GetTicks() - start_time;
	start_time = 0;
  }
}

void timer::unpause() {
  if(is_started && is_paused){
	is_paused = false;
	start_time = SDL_GetTicks() - paused_time;
	paused_time = 0;
  }
}

uint32_t timer::get_time() {
  uint32_t time = 0;
  if(is_started){
	if(is_paused) time = paused_time;
	else time = SDL_GetTicks() - start_time;
  }
  return time;
}