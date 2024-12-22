#include "BaseGameObject.h"

#include "Novice.h"

void BaseGameObject::Initialize(){

	// transformInit
	transform_.Initialize();

}

void BaseGameObject::Draw(){

	Novice::DrawEllipse(static_cast<int>( transform_.translation.x),
						static_cast<int>(transform_.translation.y),
						static_cast<int>(radius_),
						static_cast<int>(radius_), 0.0f,
						color_,
						kFillModeSolid);

}
