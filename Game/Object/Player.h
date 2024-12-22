#pragma once

#include "BaseGameObject.h"
#include "PlayerBullet.h"

#include <list>
#include <memory>

class Player :
    public BaseGameObject{
public:
	Player();
	~Player() = default;

	void Initialize() override;
	void Update() override;
	void Draw() override;

	/*===================================
			getter/setter
	==================================*/

	std::list<std::unique_ptr<PlayerBullet>>& GetBullets(){
		return bullets_;
	}

private:
	void Move();
	void Shoot();

private:
	float speed_ = 6.0f;

	std::list<std::unique_ptr<PlayerBullet>> bullets_;
};

