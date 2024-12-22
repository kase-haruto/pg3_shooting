#include <Novice.h>
#include "Game/Adapter/InputManager.h"
#include "Game/Scene/SceneManager.h"
#include <memory>

const char kWindowTitle[] = "LE2A_08_カセ_ハルト";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	InputManager::Initialize();

	std::unique_ptr<SceneManager> sceneManager = std::make_unique<SceneManager>();

	sceneManager->Run();

	InputManager::Finalize();

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
