#include "EnemyManager.h"

EnemyManager::EnemyManager(Texture2D * sprite)
{
	m_sprite = sprite;

	spawn();
}

EnemyManager::~EnemyManager()
{
}

void EnemyManager::update(float time)
{
	for (int i = 0; i < enemies.size(); ++i)
	{
		enemies[i]->move_on_yaxis(time, 1, 250);
		enemies[i]->update(time);
	}
}

void EnemyManager::draw()
{
	for (auto enemy : enemies)
	{
		enemy->draw();
	}
}

void EnemyManager::spawn()
{
	for (int i = 0; i < 7; ++i)
	{
		auto enemy = std::make_shared<Enemy>(m_sprite, glm::vec2(100 * (i + 1), 0));
		enemies.push_back(enemy);
	}
}
