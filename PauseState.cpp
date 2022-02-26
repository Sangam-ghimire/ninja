#include<vector>
#include"Game.h"
#include"PauseState.h"
#include"MenuState.h"
#include"MenuButton.h"
#include"InputHandler.h"


const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::s_pauseToMain()
{
	

	TheGame::Instance()->getStateMachine()->changeState(new
		MenuState());
}

void PauseState::s_resumePlay()
{
	TheGame::Instance()->getStateMachine()->popState();
}
void PauseState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++) 
	{
		m_gameObjects[i]->update();
	}
}
void PauseState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}
bool PauseState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/resume.png", "resume", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/menu.png", "menu", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	GameObject* button1 = new MenuButton(new LoaderParams(200, 100, 200, 80, "menu"),s_pauseToMain);
	GameObject* button2 = new MenuButton(new LoaderParams(200, 300, 200, 80, "resume"),s_resumePlay);

	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);

	std::cout << "Entering pauseState\n";

	return true;
}

bool PauseState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("resume");
	TheTextureManager::Instance()->clearFromTextureMap("main");
	//sets mouse button to false
	TheInputHandler::Instance()->reset();

	std::cout << "Exiting PauseState\n";
	return true;
}


