#include "Background.h"
#include "Engine.h"

Background::Background() : current_uv(0), speed(0.1f)
{
	tex = std::make_shared<Texture2D>("res/space_bg.jpg");
	rect = std::make_shared<Rectangle>(glm::vec2(0), Engine::window_size());
}

Background::~Background()
{
}

void Background::update(float time)
{
	current_uv -= (speed * time);
}

void Background::draw()
{
	Engine::sp_renderer->Draw(tex.get(), *rect, 0.0f, current_uv, glm::vec4(1));
}
