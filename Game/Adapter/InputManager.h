#pragma once

class InputManager{
public:

	//instance
	static InputManager* GetInstance();

	//move.参照の禁止
	InputManager(const InputManager&) = delete;
	InputManager& operator=(const InputManager&) = delete;

public:
	static void Initialize();
	static void Update();
	static void Finalize();

	static bool PushKey(int key);
	static bool TriggerKey(int key);
	static bool ReleaseKey(int key);

private:
	InputManager();
	~InputManager() = default;

private:
	static InputManager* instance_;

	// キー入力結果を受け取る箱
	static char keys[256];
	static char preKeys[256];
};


