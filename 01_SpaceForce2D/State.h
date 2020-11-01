#pragma once
#include "Texture2D.h"
#include "Rectangle.h"
#include "TimeStep.h"

class Game;

class State
{
public:
	virtual void update(Game* game, TimeStep time) = 0;
	virtual void draw() = 0;
};