#include "Engine.h"
#include "Game.h"

#include <memory>

void run()
{
	auto engine = std::make_shared<Engine>();
	engine->start(std::make_shared<Game>(), "SpaceForce2D", 900, 900);
}

int main()
{
	run();
	return 0;
}