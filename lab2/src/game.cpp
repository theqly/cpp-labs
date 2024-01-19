#include <game.h>

#include <SDL_image.h>

game::game(int screen_width, int screen_height) : is_running(true),
												  screen_width_(screen_width),
												  screen_height_(screen_height),
												  window_(nullptr),
												  renderer_(nullptr),
												  map_(),
												  player_(nullptr) {}

game::~game() {
	close();
}

void game::init() {
	if (SDL_Init(SDL_INIT_EVERYTHING!=0)) {
		is_running = false;
	}
	window_ = SDL_CreateWindow("Sprout Lands",
							   SDL_WINDOWPOS_CENTERED,
							   SDL_WINDOWPOS_CENTERED,
							   screen_width_,
							   screen_height_,
							   SDL_WINDOW_BORDERLESS);
	if (!window_) {
		throw std::runtime_error("cant create a window");
	}
	renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!renderer_) {
		throw std::runtime_error("cant create a renderer");
	}

	camera_ = {0, 0, screen_width_, screen_height_};

	player_ = player(renderer_, 500, 500);
	map_ = map(renderer_, 100, 80);

	player_.load_texture("../assets/char.bmp");
	player_.set_camera(camera_);
	player_.render(camera_);

	map_.load("../assets/map.txt");
	map_.render(camera_);
}

void game::run() {
	init();
	gameloop();
}

void game::gameloop() {
	uint32_t counter_frames = 0;
	fps_timer.start();
	while (is_running) {
		cap_timer.start();
		keyboard_event();
		update();
		render();
		++counter_frames;
		uint32_t cur_frame_time = cap_timer.get_time();
		if (cur_frame_time < frame_time) SDL_Delay(frame_time - cur_frame_time);
		cap_timer.stop();
	}
	fps_timer.stop();
}

void game::keyboard_event() {
	SDL_Event e;
	while (SDL_PollEvent(&e)!=0) {
		if (e.type==SDL_QUIT) {
			is_running = false;
		} else if (e.type==SDL_KEYDOWN) {
			switch (e.key.keysym.sym) {
				case SDLK_ESCAPE: is_running = false;
					break;
			}
		}
		map_.handle_events(e, player_);
		player_.handle_events(e);
	}
}

void game::update() {
	map_.update();
	player_.move();
	player_.set_camera(camera_);
}

void game::render() {
	SDL_RenderClear(renderer_);
	map_.render(camera_);
	player_.render(camera_);
	SDL_RenderPresent(renderer_);
}

void game::close() {
	SDL_DestroyRenderer(renderer_);
	renderer_ = nullptr;
	SDL_DestroyWindow(window_);
	window_ = nullptr;
	IMG_Quit();
	SDL_Quit();
}