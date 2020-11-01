#pragma once
#include "Window.h"
#include <map>

class Keyboard
{
public:
	Keyboard();

	~Keyboard();

	enum KeyState
	{
		State_Down, State_Up, State_None
	};

	enum Keys
	{
		ARROW_UP,
		ARROW_DOWN,
		ARROW_LEFT,
		ARROW_RIGHT,
		SPACE,
		ENTER,
		ESC
	};

	static KeyState getkey(Keys key);

	static void KeyboardFunc(GLFWwindow* window, int key, int scancode, int action, int mods);

private:
	static std::map<Keys, KeyState> m_data;
};

typedef std::shared_ptr<Keyboard> KeyboardPtr;