#pragma once
#include "IScene.h"

class TitleScene :
    public IScene{
public:
	TitleScene() = default;
	~TitleScene() = default;
	
	void Initialize() override;
	void Update() override;
	void Draw() override;

private:

	int textureHandle_;
};

