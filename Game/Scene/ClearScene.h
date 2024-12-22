#pragma once
#include "IScene.h"

class ClearScene:public IScene{
public:
	ClearScene() = default;
	~ClearScene() = default;

	void Initialize() override;
	void Update() override;
	void Draw() override;

private:
	int textureHandle_;
};

