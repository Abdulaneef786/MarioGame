#pragma once
#include <string>
#include <vector>
#include <d3d9.h>
#include <d3dx9.h>

#include "AnimationFrame.h"
#include "Sprites.h"
#include "GameObject.h"
#include "Transform.h"

using namespace std; 

class GameObject;
typedef GameObject* LPGAMEOBJECT;

class Animations;
typedef Animations* LPANIMATION;

class Animations {
	string id;
	int currentFrame;
	DWORD defaultFrameTime, lastFrameTime;
	bool isLoop, isPlaying;

	Transform transform;
	D3DXVECTOR2 localPosition;

	vector<LPANIMATIONFRAME> animationSet;
	GameObject* gameObject; 

public: 
	Animations(string id, DWORD defaultTime = 100);

	// This function was created with the intention 
	// to made a copy of the AnimationSet to GameObject
	// instead of using a pointer to AnimationSet. 
	// Also, which mean it will run directly on RAM  
	Animations(const Animations& obj);

	~Animations();
	
	void Render(D3DXVECTOR2 position, int alpha = 255);

	void SetPlay(bool isPause); // Need to work on 
	bool GetPlayStatus() { return isPlaying; }

	void AddAnimationFrame(LPSPRITE sprite, 
		D3DXVECTOR2 position, // use for animation with fixed position  
		DWORD frameTime = 0);
	LPANIMATIONFRAME GetAnimationFrame(); 

	void SetPosition(D3DXVECTOR2 p) { this->transform.SetPosition() = p; } // local position
	D3DXVECTOR2 GetPosition() { return transform.; }

	void SetScale(D3DXVECTOR2 newScale) { this->transform.scale = newScale; }
	D3DXVECTOR2 GetScale() { return transform.scale; }

	void SetRotation(float angle) { this->transform.rotationAngle = angle; }
	float GetRotation() { return transform.rotationAngle; }

	void SetAnimationLoop(bool isLoop) { this->isLoop = isLoop; }
	bool GetAnimationLoop() { return isLoop; }

	void SetRelativePosition(D3DXVECTOR2 pos) { this->relativePosition = pos; }
	D3DXVECTOR2 GetRelativePosition() { return relativePosition; }

	void SetGameObject(LPGAMEOBJECT obj) { gameObject = obj; }
	LPGAMEOBJECT GetGameObject() { return gameObject; }
};

