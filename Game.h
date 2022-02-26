#ifndef __Game__
#define __Game__

#include <vector>

#include "SDL.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include"GameStateMachine.h"

#define g_screenWidthX 640
#define g_screenBreadthY 640

class Game
{
public:
	Game() {};//change1
	~Game() {};

	GameStateMachine* getStateMachine() { return m_pGameStateMachine; }

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	//int m_screenWidth() { return m_screenBreadthY; }


	bool running() { return m_bRunning; }
	
	void quit() { m_bRunning = false; }

	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;//missing
	}



private:
	

	SDL_Window* m_pWindow{};
	SDL_Renderer* m_pRenderer{};
	SDL_Texture* m_pTexture{};
	SDL_Rect m_sourceRectangle{};
	SDL_Rect m_destinationRectangle{};

	bool m_bRunning{};
	int m_currentFrame{};

	std::vector<GameObject*> m_gameObjects;

	static Game* s_pInstance;
	GameStateMachine* m_pGameStateMachine;
};

typedef Game TheGame;
#endif // __Game__
