#include "InputManager.h"

#include <Novice.h>

char InputManager::keys[256] = {0};
char InputManager::preKeys[256] = {0};
InputManager* InputManager::instance_ = nullptr;

InputManager::InputManager(){}

InputManager* InputManager::GetInstance(){
	if (!instance_){
		instance_ = new InputManager();
	}

	return instance_;
}


void InputManager::Initialize(){

	GetInstance();

}

void InputManager::Update(){
	// キー入力を受け取る
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);
}

void InputManager::Finalize(){

	if (instance_){
		delete instance_;
	}

}

bool InputManager::PushKey(int key){
	return keys[key] != 0;
}

bool InputManager::TriggerKey(int key){
	return keys[key] != 0 && preKeys[key] == 0;
}

bool InputManager::ReleaseKey(int key){
	return keys[key] == 0 && preKeys[key] != 0;
}
