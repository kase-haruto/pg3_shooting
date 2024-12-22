#include "ClearScene.h"

#include "../Adapter/InputManager.h"
#include <Novice.h>

void ClearScene::Initialize(){

	textureHandle_ = Novice::LoadTexture("./Resources/clear.png");
}

void ClearScene::Update(){
	if (InputManager::TriggerKey(DIK_SPACE)){
		sceneNum_ = static_cast< int >(SceneType::TITLE);
	}
}

void ClearScene::Draw(){

	Novice::DrawQuad(
		0, 0, 1280, 0,
		0, 720, 1280, 720,
		1, 1, 1280, 720,
		textureHandle_, 0xffffffff);

}
