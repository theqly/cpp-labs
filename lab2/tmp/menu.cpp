#include <menu.h>

#include <SDL_image.h>

menu::menu() : is_running(true),
			   is_game_started(false),
			   screen_width_(1280),
			   screen_height_(720),
			   window_(nullptr),
			   renderer_(nullptr),
			   background_(),
			   start_button_x(screen_width_ * 3 / 8),
			   start_button_y(screen_height_ * 3 / 8),
			   start_button_(start_button_x, start_button_y),
			   game_(){}

menu::~menu(){
  close();
}

void menu::init() {
  if(SDL_Init(SDL_INIT_EVERYTHING != 0)){
	is_running = false;
  }
  window_ = SDL_CreateWindow("Sprout Lands", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width_, screen_height_, SDL_WINDOW_BORDERLESS);
  renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  background_.load("../assets/menu2.jpg", renderer_);
  background_.render(0, 0);

  start_button_.load();
  start_button_.render();
}

void menu::start(){
  init();
  loop();
}

void menu::loop() {
  while (is_running){
	keyboard_event();
	update();
	render();
  }
}

void menu::keyboard_event() {
  SDL_Event e;
  while( SDL_PollEvent( &e ) != 0 ) {
	if (e.type == SDL_QUIT) {
	  is_running = false;
	}
	else if (e.type==SDL_KEYDOWN) {
	  switch (e.key.keysym.sym) {
		case SDLK_ESCAPE: is_running = false;
		  break;
	  }
	}
	start_button_.handle_events(&e);
  }
}

void menu::update() {
  if(is_game_started){
	is_running = false;
	close();
	run_game();
  }
}

void menu::render() {
  SDL_RenderClear(renderer_);
  background_.render(0,0);
  start_button_.render();
  SDL_RenderPresent(renderer_);
}

void menu::run_game() {
  close();
  game_.run();
}

void menu::close() {
  background_.clear();
  SDL_DestroyRenderer(renderer_);
  renderer_ = nullptr;
  SDL_DestroyWindow(window_);
  window_ = nullptr;
  IMG_Quit();
  SDL_Quit();
}