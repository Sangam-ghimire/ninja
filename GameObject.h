#ifndef __GameObject__
#define __GameObject__

#include <iostream>

#include "LoaderParams.h"
#include"SDL.h"
#include"Vector2D.h"

class GameObject
{
public:

	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;

protected:

	GameObject(const LoaderParams* pParams) {}

	virtual ~GameObject() {}
};

#endif // __GameObject__
