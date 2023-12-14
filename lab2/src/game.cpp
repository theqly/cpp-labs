#include <game.h>

#include <SDL_image.h>

game::game() : is_running(true), screen_width_(1280), screen_height_(720), window_(nullptr), renderer_(nullptr), background_(), start_button_(){}

game::~game(){
  close();
}

void game::init() {
  if(!SDL_Init(SDL_INIT_EVERYTHING)){
	is_running = false;
  }
  window_ = SDL_CreateWindow("Sprout Lands", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width_, screen_height_, SDL_WINDOW_BORDERLESS);
  renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);

  background_.set_renderer(renderer_);
  background_.load("../assets/menu2.jpg");
  background_.render(0, 0);

  start_button_.set_renderer(renderer_);
  start_button_.load("../assets/start_button.jpg");
  background_.render(screen_width_ * 3 / 8, screen_height_ * 3 /8);
}

void game::run(){
  init();
  gameloop();
}

void game::gameloop() {
  while (is_running){
	keyboard_event();
	update();
	render();
  }
}

void game::keyboard_event() {
  SDL_Event e;
  while( SDL_PollEvent( &e ) != 0 ) {
	if (e.type == SDL_QUIT) {
	  is_running = false;
	}
	else if (e.type==SDL_KEYDOWN) {
	  switch (e.key.keysym.sym) {
		case SDLK_ESCAPE: is_running = false;
		  break;
		case SDLK_q: start_button_.red += 32;
		  break;
		case SDLK_w: start_button_.green += 32;
		  break;
		case SDLK_e: start_button_.blue += 32;
		  break;
		case SDLK_a: start_button_.red -= 32;
		  break;
		case SDLK_s: start_button_.green -= 32;
		  break;
		case SDLK_d: start_button_.blue -= 32;
		  break;
	  }
	}
  }
}

void game::update() {

}

void game::render() {
  SDL_RenderClear(renderer_);
  background_.render(0,0);
  start_button_.apply_color();
  start_button_.render(screen_width_ * 3 / 8, screen_height_ * 3 /8);
  SDL_RenderPresent(renderer_);
}

void game::close() {
  background_.clear();
  start_button_.clear();
  SDL_DestroyRenderer(renderer_);
  renderer_ = nullptr;
  SDL_DestroyWindow(window_);
  window_ = nullptr;
  IMG_Quit();
  SDL_Quit();
}