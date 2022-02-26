#pragma once
#include"GameState.h"
#include<iostream>
#include<vector>

class GameStateMachine
{
private:
	std::vector<GameState*> m_gameStates;

public:
	void pushState(GameState* pState);//add a state without removing prev state
	void changeState(GameState* pState);//will remove prev state before adding new state
	void popState();//will remove currently being used state
	
	void update();
	void render();

};