#pragma once
#include "IScene.h"

#include <cstdint>
#include <array>
#include <memory>
class SceneManager{
public:
	SceneManager();
	~SceneManager() = default;

	int Run();

private:
	uint32_t currentSceneNo_;
	uint32_t prevSceneNo_;

	std::array<std::unique_ptr<IScene>, static_cast< int >(SceneType::count)>scenes_;
};

