#include <iostream>
#include "Game.h"

// our Game object
Game* g_game = 0;

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS ;//defing frame per second for our game to run at

int main(int argc, char* args[])
{
	std::cout << "game init attempt...\n";
	Uint32 frameStart, frameTime;

	if (TheGame::Instance()->init("BAGHCHAAL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,g_screenWidthX, g_screenBreadthY, false))
	{
		std::cout << "game init success!\n";
		while (TheGame::Instance()->running())
		{
			frameStart = SDL_GetTicks();

			TheGame::Instance()->handleEvents();
			TheGame::Instance()->update();
			TheGame::Instance()->render();

			frameTime = SDL_GetTicks() - frameStart;

			if (frameTime<DELAY_TIME)
			{
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}

			
		}
	}
	else
	{
		std::cout << "game init failure - " << SDL_GetError() << "\n";
		return -1;
	}

	std::cout << "game closing...\n";
	TheGame::Instance()->clean();

	return 0;
}


