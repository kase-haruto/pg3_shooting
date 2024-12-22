#pragma once

#include <math/Vector3.h>
#include <cstdint>

class BaseGameObject{
public:
	BaseGameObject() = default;
	~BaseGameObject() = default;
	
	virtual void Initialize();
	virtual void Update() = 0;
	virtual void Draw();

	float GetRadius(){
		return 32.0f;
	}

protected:
	uint32_t color_;
	float radius_ = 32.0f;

public:
	KamataEngine::Transform transform_;
	int32_t life_;

};

