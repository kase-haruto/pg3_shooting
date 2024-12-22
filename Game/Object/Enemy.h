#pragma once
#include "BaseGameObject.h"


class Enemy :
    public BaseGameObject{
public:
	Enemy() = default;
	~Enemy() = default;

	void Initialize() override;
	void Update() override;
	void Draw() override;

	bool IsDead(){
		return life_ <= 0;
	}

private:
	float speed_ = 5.0f;

};

