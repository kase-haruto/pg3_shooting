#pragma once
#include "IScene.h"

#include "../Object/Player.h"
#include "../Object/Enemy.h"

#include <memory>


class PlayScene :
    public IScene{

public:
	PlayScene() = default;
	~PlayScene() = default;
	void Initialize() override;
	void Update() override;
	void Draw() override;

private:

	std::unique_ptr<Player> player;
	std::unique_ptr<Enemy> enemy;
};

