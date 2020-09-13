#include "Keyboard.h"

std::map<Keyboard::Keys, Keyboard::KeyState> Keyboard::m_data;

Keyboard::Keyboard()
{
}

Keyboard::~Keyboard()
{
}


Keyboard::KeyState Keyboard::getkey(Keys key)
{
	auto it = m_data.find(key);

	if (it == m_data.end())
		return Keyboard::KeyState::State_None;

	return it->second;
}

void Keyboard::KeyboardFunc(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	switch (key)
	{
		case GLFW_KEY_UP:
		{
			auto flag = (action == GLFW_PRESS || action == GLFW_REPEAT) ? KeyState::State_Down : KeyState::State_Up;
			auto in = std::make_pair(Keys::ARROW_UP, flag);
			if (flag == KeyState::State_Down) m_data.insert(in);
			else m_data.erase(in.first);
			break;
		}
		case GLFW_KEY_DOWN:
		{
			auto flag = (action == GLFW_PRESS || action == GLFW_REPEAT) ? KeyState::State_Down : KeyState::State_Up;
			auto in = std::make_pair(Keys::ARROW_DOWN, flag);
			if (flag == KeyState::State_Down) m_data.insert(in);
			else m_data.erase(in.first);
			break;
		}
		case GLFW_KEY_RIGHT:
		{
			auto flag = (action == GLFW_PRESS || action == GLFW_REPEAT) ? KeyState::State_Down : KeyState::State_Up;
			auto in = std::make_pair(Keys::ARROW_RIGHT, flag);
			if (flag == KeyState::State_Down) m_data.insert(in);
			else m_data.erase(in.first);
			break;
		}
		case GLFW_KEY_LEFT:
		{
			auto flag = (action == GLFW_PRESS || action == GLFW_REPEAT) ? KeyState::State_Down : KeyState::State_Up;
			auto in = std::make_pair(Keys::ARROW_LEFT, flag);
			if (flag == KeyState::State_Down) m_data.insert(in);
			else m_data.erase(in.first);
			break;
		}
		case GLFW_KEY_SPACE:
		{
			auto flag = (action == GLFW_PRESS || action == GLFW_REPEAT) ? KeyState::State_Down : KeyState::State_Up;
			auto in = std::make_pair(Keys::SPACE, flag);
			if (flag == KeyState::State_Down) m_data.insert(in);
			else m_data.erase(in.first);
			break;
		}
		case GLFW_KEY_ESCAPE:
		{
			auto flag = (action == GLFW_PRESS || action == GLFW_REPEAT) ? KeyState::State_Down : KeyState::State_Up;
			auto in = std::make_pair(Keys::ESC, flag);
			if (flag == KeyState::State_Down) m_data.insert(in);
			else m_data.erase(in.first);
			break;
		}
		default:
		{
			break;
		}
	}
}