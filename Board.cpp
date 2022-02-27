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

	std::cout << "Mouse position=x:" << TheInputHandler::Instance()->m_mousePosition->getX() << ",y:" << TheInputHandler::Instance()->m_mousePosition->getY() << std::endl;
	TheBoard::Instance()->filtercoordinate();
}
void Board::filtercoordinate()
{
	if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		if (TheInputHandler::Instance()->m_mousePosition->getX() >= (0) &&
			TheInputHandler::Instance()->m_mousePosition->getX() <= (g_screenWidthX / 5))
		{
			if (TheInputHandler::Instance()->m_mousePosition->getY() >= 0 &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(0);
				TheBoard::Instance()->setRY(0);
			}
			else if(TheInputHandler::Instance()->m_mousePosition->getY() >= (g_screenBreadthY/5) &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= 2*(g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(0);
				TheBoard::Instance()->setRY(g_screenBreadthY / 5);
			}
			else if (TheInputHandler::Instance()->m_mousePosition->getY() >= 2*(g_screenBreadthY / 5) &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= 3*(g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(0);
				TheBoard::Instance()->setRY((2*g_screenBreadthY / 5));
			}
			else if (TheInputHandler::Instance()->m_mousePosition->getY() >= 3 * (g_screenBreadthY / 5) &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= 4*(g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(0);
				TheBoard::Instance()->setRY(3*g_screenBreadthY/5);
			}
			else {
				TheBoard::Instance()->setRX(0);
				TheBoard::Instance()->setRY(4 * g_screenBreadthY / 5);
			}

		}
		else if (TheInputHandler::Instance()->m_mousePosition->getX() >= (g_screenWidthX/5) &&
			TheInputHandler::Instance()->m_mousePosition->getX() <= (2*g_screenWidthX / 5))
		{
			if (TheInputHandler::Instance()->m_mousePosition->getY() >= 0 &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(g_screenWidthX/5);
				TheBoard::Instance()->setRY(0);
			}
			else if (TheInputHandler::Instance()->m_mousePosition->getY() >= (g_screenBreadthY / 5) &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= 2 * (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(g_screenWidthX / 5);
				TheBoard::Instance()->setRY(g_screenBreadthY / 5);
			}
			else if (TheInputHandler::Instance()->m_mousePosition->getY() >= 2 * (g_screenBreadthY / 5) &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= 3 * (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(g_screenWidthX / 5);
				TheBoard::Instance()->setRY((2 * g_screenBreadthY / 5));
			}
			else if (TheInputHandler::Instance()->m_mousePosition->getY() >= 3 * (g_screenBreadthY / 5) &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= 4*(g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(g_screenWidthX / 5);
				TheBoard::Instance()->setRY(3 * g_screenBreadthY / 5);
			}else {
				TheBoard::Instance()->setRX(g_screenWidthX / 5);
				TheBoard::Instance()->setRY(4* g_screenBreadthY / 5);
			}
		}
		else if (TheInputHandler::Instance()->m_mousePosition->getX() >= (2 * g_screenWidthX / 5) &&
			TheInputHandler::Instance()->m_mousePosition->getX() <= (3 * g_screenWidthX / 5))
		{
			if (TheInputHandler::Instance()->m_mousePosition->getY() >= 0 &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(2 * g_screenWidthX / 5);
				TheBoard::Instance()->setRY(0);
			}
			else if (TheInputHandler::Instance()->m_mousePosition->getY() >= (g_screenBreadthY / 5) &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= 2 * (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(2*g_screenWidthX / 5);
				TheBoard::Instance()->setRY(g_screenBreadthY / 5);
			}
			else if (TheInputHandler::Instance()->m_mousePosition->getY() >= 2 * (g_screenBreadthY / 5) &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= 3 * (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(2*g_screenWidthX / 5);
				TheBoard::Instance()->setRY((2 * g_screenBreadthY / 5));
			}
			else if (TheInputHandler::Instance()->m_mousePosition->getY() >= 3 * (g_screenBreadthY / 5) &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= 4*(g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(2*g_screenWidthX / 5);
				TheBoard::Instance()->setRY(3 * g_screenBreadthY / 5);
			}
			else {
				TheBoard::Instance()->setRX(2 * g_screenWidthX / 5);
				TheBoard::Instance()->setRY(4 * g_screenBreadthY / 5);
			}
		}
		else if (TheInputHandler::Instance()->m_mousePosition->getX() >= 3*(g_screenWidthX / 5) &&
			TheInputHandler::Instance()->m_mousePosition->getX() <= (4 * g_screenWidthX / 5))
		{
			if (TheInputHandler::Instance()->m_mousePosition->getY() >= 0 &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(3*g_screenWidthX / 5);
				TheBoard::Instance()->setRY(0);
			}
			else if (TheInputHandler::Instance()->m_mousePosition->getY() >= (g_screenBreadthY / 5) &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= 2 * (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(3*g_screenWidthX / 5);
				TheBoard::Instance()->setRY(g_screenBreadthY / 5);
			}
			else if (TheInputHandler::Instance()->m_mousePosition->getY() >= 2 * (g_screenBreadthY / 5) &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= 3 * (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(3*g_screenWidthX / 5);
				TheBoard::Instance()->setRY((2 * g_screenBreadthY / 5));
			}
			else if (TheInputHandler::Instance()->m_mousePosition->getY() >=  3* (g_screenBreadthY / 5) &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= 4*(g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(3*g_screenWidthX / 5);
				TheBoard::Instance()->setRY(3 * g_screenBreadthY / 5);
			}
			else {
				TheBoard::Instance()->setRX(3 * g_screenWidthX / 5);
				TheBoard::Instance()->setRY(4 * g_screenBreadthY / 5);
			}
		}
		else if (TheInputHandler::Instance()->m_mousePosition->getX() >= (4 * g_screenWidthX / 5) &&
			TheInputHandler::Instance()->m_mousePosition->getX() <= (5 * g_screenWidthX / 5))
		{
			if (TheInputHandler::Instance()->m_mousePosition->getY() >= 0 &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(4 * g_screenWidthX / 5);
				TheBoard::Instance()->setRY(0);
			}
			else if (TheInputHandler::Instance()->m_mousePosition->getY() >= (g_screenBreadthY / 5) &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= 2 * (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(4 * g_screenWidthX / 5);
				TheBoard::Instance()->setRY(g_screenBreadthY / 5);
			}
			else if (TheInputHandler::Instance()->m_mousePosition->getY() >= 2 * (g_screenBreadthY / 5) &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= 3 * (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(4 * g_screenWidthX / 5);
				TheBoard::Instance()->setRY((2 * g_screenBreadthY / 5));
			}
			else if (TheInputHandler::Instance()->m_mousePosition->getY() >= 3 * (g_screenBreadthY / 5) &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= 4 * (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(4 * g_screenWidthX / 5);
				TheBoard::Instance()->setRY(3 * g_screenBreadthY / 5);
			}
			else {
				TheBoard::Instance()->setRX(4 * g_screenWidthX / 5);
				TheBoard::Instance()->setRY(4 * g_screenBreadthY / 5);
			}
		}

	}
	std::cout << TheBoard::Instance()->getR_X()<<"," << TheBoard::Instance()->getR_Y() << std::endl;

}
void Board::render()
{
	TheBoard::Instance()->createBoard();

	TheTextureManager::Instance()->load("assets/bagchalBoard.png", "board", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->draw("board", 64, 64, 512, 512, TheGame::Instance()->getRenderer());

}
//void Board::turn()
//{
	//while (!gameoverstate)
	//{
	//	bool turngoat = true;
	//	while (turngoat)
	//	{
	//		//goat lai move garney
	//		turngoat = !turngoat;
	//	}
	//	while (!turngoat)
	//	{
	//		//tiger move garney
	//		turngoat = !turngoat;

	//	}
	//}

//}

