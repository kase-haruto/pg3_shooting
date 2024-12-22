#include "TitleScene.h"

#include "../Adapter/InputManager.h"
#include <Novice.h>

void TitleScene::Initialize(){

	textureHandle_ = Novice::LoadTexture("./Resources/title.png");

}

void TitleScene::Update(){

	if (InputManager::TriggerKey(DIK_SPACE)){
		sceneNum_ = static_cast< int >(SceneType::PLAY);
	}

}

void TitleScene::Draw(){

	Novice::DrawQuad(
		0, 0, 1280, 0,
		0, 720, 1280, 720,
		1, 1, 1280, 720,
		textureHandle_, 0xffffffff);
}
