#pragma once

class Board {
public:
	static Board* s_pInstance;
	static Board* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Board();
			return s_pInstance;
		}
		return s_pInstance;
	}
	void createBoard();

};
typedef Board TheBoard;