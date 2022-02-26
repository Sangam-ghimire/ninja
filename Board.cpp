#include"Board.h"
#include"TextureManager.h"
#include"Game.h"
#include"GameObject.h"
#include"SDLGameObject.h"
#include"LoaderParams.h"
#include"InputHandler.h"
#include"Vector2D.h"

Board* TheBoard::s_pInstance = 0;

void Board::createBoard() {
	bool white = true;
	SDL_SetRenderDrawColor(TheGame::Instance()->getRenderer(), 255, 255, 255, 255);

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (white)
			{
				SDL_SetRenderDrawColor(TheGame::Instance()->getRenderer(), 255, 255, 255, 255);
			}
			else
			{
				SDL_SetRenderDrawColor(TheGame::Instance()->getRenderer(), 155, 103, 60, 255);
			}
			white = !white;
			SDL_Rect rectangle = { i * g_screenWidthX / 5,
								  j * g_screenBreadthY / 5,
								  g_screenWidthX / 5,
								  g_screenBreadthY / 5 };
			SDL_RenderFillRect(TheGame::Instance()->getRenderer(), &rectangle);
			
		}
		white = !white;
	}//ok	
	
}
void Board::coordinate() {
	std::cout << "Mouse position=x:" << TheInputHandler::Instance()->m_mousePosition->getX() << ",y:" << TheInputHandler::Instance()->m_mousePosition->getY()<< std::endl;

}

