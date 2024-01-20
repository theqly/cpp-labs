#include "game.h"

int main(int argc, char **argv) {
	game sprout_lands(1980, 1080);
	try{
		sprout_lands.run();
	}
	catch(const std::runtime_error& e){
		std::cout << e.what() << std::endl;
	}
	return 0;
}