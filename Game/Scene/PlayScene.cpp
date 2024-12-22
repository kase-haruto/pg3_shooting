#include "PlayScene.h"

#include <Novice.h>
#include "../Adapter/InputManager.h"

void PlayScene::Initialize(){

	player = std::make_unique<Player>();
	player->Initialize();

	enemy = std::make_unique<Enemy>();
	enemy->Initialize();

}

void PlayScene::Update(){

	player->Update();
	enemy->Update();

	//===================================================================*/
	//                    collision
	//===================================================================*/

	//bullet vs enemy
	for (auto& bullet : player->GetBullets()){
		float bulletRadius = bullet->GetRadius();
		float enemyRadius = enemy->GetRadius();
		float distance = sqrtf((bullet->transform_.translation.x - enemy->transform_.translation.x) * (bullet->transform_.translation.x - enemy->transform_.translation.x) +
							   (bullet->transform_.translation.y - enemy->transform_.translation.y) * (bullet->transform_.translation.y - enemy->transform_.translation.y));
		if (distance < bulletRadius + enemyRadius){
			bullet->SetIsAlive(false);
			enemy->life_--;
		}
	}

	if (enemy->IsDead()){
		sceneNum_ = static_cast< int >(SceneType::CLEAR);
	}

	if (InputManager::TriggerKey(DIK_1)){
		sceneNum_ = static_cast< int >(SceneType::TITLE);
	}
}

void PlayScene::Draw(){

	player->Draw();
	enemy->Draw();

}
