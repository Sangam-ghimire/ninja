#pragma once
#include"SDLGameObject.h"
#include"LoaderParams.h"

class MenuButton : public SDLGameObject
{
public:
	MenuButton(const LoaderParams* pParams,void(*callback)());

	virtual void draw();
	virtual void update();
	virtual void clean();
	
private:
	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};
	bool m_bReleased;
	void(*m_callback)();
};