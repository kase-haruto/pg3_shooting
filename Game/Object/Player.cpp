#include "Player.h"
#include "Novice.h"

#include "../Adapter/InputManager.h"

Player::Player(){
	bullets_.clear();
}

void Player::Initialize(){
	life_ = 3;
	color_ = 0xffffffff;
	BaseGameObject::Initialize();

	transform_.translation.x = 1280.0f * 0.5f;
	transform_.translation.y = 600.0f;
}

void Player::Update(){

	bullets_.remove_if([] (const std::unique_ptr<PlayerBullet>& bullet){
		return !bullet->GetIsAlive();
					   });

	Move();

	Shoot();

	for (auto& bullet : bullets_){
		bullet->Update();
	}

}

void Player::Draw(){

	BaseGameObject::Draw();
	for (auto& bullet : bullets_){
		bullet->Draw();
	}

}

////////////////////////////////////////////////////////////////////////////////////////////
//				helper functions
////////////////////////////////////////////////////////////////////////////////////////////
void Player::Move(){

	if (InputManager::PushKey(DIK_D)){
		transform_.translation.x += speed_;
	} else if (InputManager::PushKey(DIK_A)){
		transform_.translation.x -= speed_;
	}

	if (InputManager::PushKey(DIK_W)){
		transform_.translation.y -= speed_;
	} else if (InputManager::PushKey(DIK_S)){
		transform_.translation.y += speed_;
	}

}

void Player::Shoot(){

	if (InputManager::TriggerKey(DIK_SPACE)){
		auto bullet = std::make_unique<PlayerBullet>();
		bullet->Initialize();
		bullet->SetPos(transform_.translation);
		bullets_.push_back(std::move(bullet));
	}

}
