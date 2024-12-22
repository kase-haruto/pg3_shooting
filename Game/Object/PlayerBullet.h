#pragma once
#include "BaseGameObject.h"


class PlayerBullet :
    public BaseGameObject{
public:
	PlayerBullet() = default;
	~PlayerBullet() = default;

	void Initialize() override;
	void Update() override;
	void Draw() override;

	/*===================================
			getter/setter
	==================================*/
	void SetPos(KamataEngine::Vector3 pos){
		transform_.translation = pos;
	}

	float GetRadius(){
		return 8.0f;
	}

	void SetIsAlive(bool isAlive){
		isAlive_ = isAlive;
	}

	bool GetIsAlive(){
		return isAlive_;
	}

private:
	bool isAlive_ = true;
	float speed_ = 5.0f;
	float radius_ = 8.0f;
};

