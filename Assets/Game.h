
//	Game.h																				  

#pragma once

#include "D3DGraphics.h"
#include "Keyboard.h"

class Game {

public:
	
	Game(HWND hWnd, const KeyboardServer& kServer);
	void Go();
	void getCross(int, int);
private:
	int x;
	int y;
	void ComposeFrame();
	
private:
	D3DGraphics gfx;
	KeyboardClient kbd;

};