#include <iostream>
#include "SDL.h"
#include"Board.h"

#include "Player.h"
#include"InputHandler.h"
#include"TextureManager.h"
#include"Game.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Player::draw()
{
	SDLGameObject::draw();

}

void Player::update()
{
	handleInput();

	m_currentFrame = int(((SDL_GetTicks() / 100) %1));
	
	SDLGameObject::update();
}


void Player::handleInput()
{ 
	int x = TheBoard::Instance()->getR_X();
	int y = TheBoard::Instance()->getR_Y();
	m_position.setX(x);
	m_position.setY(y);
	if(x== m_position.getX() && y== m_position.getY()){
		int x1 = TheBoard::Instance()->getR_X();
		int y1= TheBoard::Instance()->getR_Y();
		m_position.setX(x1);
		m_position.setY(y1);
		
	}
	//std::cout <<"this is the value x of object="<< m_position.getX()<<std::endl;
	//std::cout << "this is the value y of object=" << m_position.getY() << std::endl;


	/*m_position.setX(TheBoard::Instance()->getR_X());
	m_position.setY(TheBoard::Instance()->getR_Y());*/
		
}

void Player::clean() {}
