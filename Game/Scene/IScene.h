#pragma once


enum class SceneType{
	TITLE,
	PLAY,
	CLEAR,
	count,
};

class IScene{
public:
	IScene() = default;
	virtual ~IScene() = default;
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	int GetSceneNum(){
		return sceneNum_;
	}

public:

	static int sceneNum_;
};



