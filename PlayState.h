#pragma once
#include"GameState.h"
#include"GameObject.h"
#include<vector>

//class GameObject;

class PlayState :public GameState
{
private:
	static const std::string s_playID;

	std::vector<GameObject*>m_gameObjects;

public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_playID; }
	
};