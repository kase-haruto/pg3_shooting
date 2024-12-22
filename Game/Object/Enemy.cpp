#include "Enemy.h"

void Enemy::Initialize(){

	speed_ = 5.0f;
	color_ = 0xff0000ff;
	life_ = 1;

	transform_.translation.x = 1280.0f * 0.5f;
	transform_.translation.y = 100.0f;

}

void Enemy::Update(){
	transform_.translation.x += speed_;

	if (transform_.translation.x <= 0.0f ||
		transform_.translation.x >= 1280.0f){
		speed_ *= -1.0f;
	}
}

void Enemy::Draw(){
	if (life_>0){
	
		BaseGameObject::Draw();

	}
}
