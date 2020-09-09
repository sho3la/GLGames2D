#include "Engine.h"
#include "Game.h"

#include <memory>

int main()
{
	auto engine = std::make_shared<Engine>();
	engine->start(std::make_shared<Game>(), "SpaceForce2D", 900, 900);
	return 0;
}