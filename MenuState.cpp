#include "MenuState.h"
#include"MenuButton.h"
#include"TextureManager.h"
#include"Game.h"
#include"PlayState.h"
#include<string>
#include<iostream>

const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void MenuState::render()
{
	
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool MenuState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/start.png", "start", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/exit.png", "exit", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject* button1 = new MenuButton(new LoaderParams(200, 100, 200, 80, "start"),s_menuToPlay);
	GameObject* button2 = new MenuButton(new LoaderParams(200, 300, 200, 80, "exit"),s_exitFromMenu);

	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout<< "Entering MenuState\n";
	return true;
}

bool MenuState::onExit()
{
	std::cout << "Exiting MenuState\n";
	return true;
}
void MenuState::s_menuToPlay()
{
	std::cout << "Play button clicked\n";
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}
void MenuState::s_exitFromMenu() 
{
	
	TheGame::Instance()->quit();	
}
