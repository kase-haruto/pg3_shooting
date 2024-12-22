#include "SceneManager.h"
#include "../Adapter/InputManager.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "ClearScene.h"


#include <Novice.h>

SceneManager::SceneManager(){
	scenes_[static_cast< int >(SceneType::TITLE)] = std::make_unique<TitleScene>();
	scenes_[static_cast< int >(SceneType::PLAY)] = std::make_unique<PlayScene>();
	scenes_[static_cast< int >(SceneType::CLEAR)] = std::make_unique<ClearScene>();
	IScene::sceneNum_ = static_cast< int >(SceneType::TITLE);
}

int SceneManager::Run(){

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0){
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		InputManager::Update();


		// シーンの更新
		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = scenes_[IScene::sceneNum_]->GetSceneNum();

		if (prevSceneNo_!= currentSceneNo_){
			scenes_[currentSceneNo_]->Initialize();
		}

		scenes_[currentSceneNo_]->Update();

		scenes_[currentSceneNo_]->Draw();


		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (InputManager::TriggerKey(DIK_ESCAPE)){
			break;
		}
	}

	return 0;
}

