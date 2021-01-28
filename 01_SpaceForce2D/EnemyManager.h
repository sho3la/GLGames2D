#pragma once
#include "Enemy.h"

#include <vector>
#include <memory>

class EnemyManager
{
public:
	EnemyManager(Texture2D* sprite);

	~EnemyManager();

	void update(float time);

	void draw();

	void spawn();

private:
	Texture2D* m_sprite;
	std::vector<std::shared_ptr<Enemy>> enemies;
};