#ifndef __Player__
#define __Player__

#include <iostream>

#include "SDLGameObject.h"

class Player : public SDLGameObject
{
private:
	void handleInput();
public:

	Player(const LoaderParams* pParams);

	void draw();
	void update();
	void clean();
};

#endif // __Player__
