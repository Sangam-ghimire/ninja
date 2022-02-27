#include"PlayState.h"
#include"TextureManager.h"
#include"Game.h"
#include"InputHandler.h"
#include"PauseState.h"
#include"Board.h"

#include<iostream>

const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
	//when escape is pressed game pauses
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->pushState(new PauseState());
	}
	
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();

	}
}
void PlayState::render()
{	
	TheBoard::Instance()->render();

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}

}
bool PlayState::onEnter()
{
	//if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat", TheGame::Instance()->getRenderer())) 
	//{
	//	return false;
	//}
	//GameObject* player = new Player(new LoaderParams(TheBoard::Instance()->getR_X(), TheBoard::Instance()->getR_Y(), 128, 55, "goat"));//player object
	if (!TheTextureManager::Instance()->load("assets/tigerMain.png", "tiger", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject* player = new Player(new LoaderParams(TheBoard::Instance()->getR_X(), TheBoard::Instance()->getR_Y(), 128, 128, "tiger"));
	m_gameObjects.push_back(player);

	std::cout << "entering PlayState\n";
	return true;
}
bool PlayState::onExit()
{
	std::cout << "exiting playstate\n";
	
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	//TheTextureManager::Instance()->clearFromTextureMap("goat");
	TheTextureManager::Instance()->clearFromTextureMap("tiger");

	
	return true;
}