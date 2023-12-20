#include <game.h>

#include <SDL_image.h>

game::game() : is_running(true),
			screen_width_(1280),
			screen_height_(720),
			window_(nullptr),
			renderer_(nullptr),
			background_(){}

game::~game(){
  close();
}

void game::init() {
  if(SDL_Init(SDL_INIT_EVERYTHING != 0)){
	is_running = false;
  }
  window_ = SDL_CreateWindow("Sprout Lands", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width_, screen_height_, SDL_WINDOW_BORDERLESS);
  if(!window_){
	std::cout << "cant open a window" << std::endl;
	is_running = false;
  }
  renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if(!renderer_){
	std::cout << "cant open a renderer" << std::endl;
	is_running = false;
  }

  if(!background_.load("../assets/menu2.jpg", renderer_)){
	std::cout << "background texture not loaded" << std::endl;
	is_running = false;
  }
  background_.render(renderer_, 0, 0);

  character.init(renderer_);
  if(!character.load_texture("../assets/char.jpg")){
	std::cout << "character texture not loaded" << std::endl;
	is_running = false;
  }
  character.render();
}

void game::run(){
  init();
  gameloop();
}

void game::gameloop() {
  uint32_t counter_frames = 0;
  fps_timer.start();
  while (is_running){
	cap_timer.start();
	keyboard_event();
	update();
	render();
	++counter_frames;
	uint32_t cur_frame_time = cap_timer.get_time();
	if(cur_frame_time < frame_time) SDL_Delay(frame_time - cur_frame_time);
	cap_timer.stop();
  }
  fps_timer.stop();
}

void game::keyboard_event() {
  SDL_Event e;
  while( SDL_PollEvent(&e) != 0 ) {
	if (e.type == SDL_QUIT) {
	  is_running = false;
	}
	else if (e.type==SDL_KEYDOWN) {
	  switch (e.key.keysym.sym) {
		case SDLK_ESCAPE: is_running = false;
		  break;
	  }
	}
	character.handle_events(e);
  }
}

void game::update() {
  character.move();
}

void game::render() {
  SDL_RenderClear(renderer_);
  background_.render(renderer_, 0,0);
  character.render();
  SDL_RenderPresent(renderer_);
}

void game::close() {
  background_.clear();
  SDL_DestroyRenderer(renderer_);
  renderer_ = nullptr;
  SDL_DestroyWindow(window_);
  window_ = nullptr;
  IMG_Quit();
  SDL_Quit();
}