#include <iostream>
#include "SDL.h"

#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::update()
{
	m_position.setX(m_position.getX()+1 );//since setX is a pointer to a bound function it may only be used to call the function
	m_position.setY(m_position.getY()+1 );

	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Enemy::clean() {}
