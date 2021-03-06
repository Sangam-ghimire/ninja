#pragma once
#include"GameState.h"
#include"GameObject.h"
#include<vector>

class PauseState :public GameState
{
private:
	static void s_pauseToMain();
	static void s_resumePlay();

	static const std::string s_pauseID;

	std::vector<GameObject*> m_gameObjects;

public:
	virtual void update();
	
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_pauseID; }

};