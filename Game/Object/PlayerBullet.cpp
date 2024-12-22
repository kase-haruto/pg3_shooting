#include "PlayerBullet.h"

#include <Novice.h>

void PlayerBullet::Initialize(){

	speed_ = 5.0f;
	color_ = 0x6c6c6cff;
	life_ = 1;
	transform_.translation.x = 1280.0f * 0.5f;
	transform_.translation.y = 100.0f;
}

void PlayerBullet::Update(){

	transform_.translation.y -= speed_;

}

void PlayerBullet::Draw(){

	Novice::DrawEllipse(static_cast< int >(transform_.translation.x),
						static_cast< int >(transform_.translation.y),
						static_cast<int>(radius_), 
						static_cast< int >(radius_), 0.0f,
						color_,
						kFillModeSolid);

}
