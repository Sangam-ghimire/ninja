#pragma once
#ifndef __InputHandler__
#define __InputHandler__

#include<vector>
#include<utility>

#include"SDL.h"
#include"Vector2D.h"

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
private:
	InputHandler();
	~InputHandler() { delete m_mousePosition; }

	static InputHandler* s_pInstance;

	std::vector<std::vector<bool>>m_buttonStates;

	std::vector<bool> m_mouseButtonStates;

	//Vector2D* m_mousePosition = NULL;
	const Uint8* m_keystates= NULL;

	//handle Keyboard events
	void onKeyDown();
	void onKeyUp();

	//handle mouse events
	void onMouseMove(SDL_Event& event);
	void onMouseButtonDown(SDL_Event& event);
	void onMouseButtonUp(SDL_Event& event);

public:
	Vector2D* m_mousePosition = NULL;
	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}


	void update();
	void clean();

	bool getMouseButtonState(int buttonNumber)
	{
		return m_mouseButtonStates[buttonNumber];
	}

	Vector2D* getMousePosition()
	{
		return m_mousePosition;
	}

	bool isKeyDown(SDL_Scancode key);

	void reset();

};
typedef InputHandler TheInputHandler;

#endif // !__InputHandler__

