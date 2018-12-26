
//	Game.cpp																		

#include "Game.h"
#include <iostream>

#define crossSize 5
#define windowsHeight 600
#define windowsWidth 700

int crossX = windowsWidth / 2, crossY = windowsHeight / 2;

// 绘制十字光标，参数：十字中心点坐标
void Game::getCross(int x, int y) {
	// 横线
	for (int i = x - crossSize; i <= x + crossSize; i++) {
		gfx.PutPixel(i, y, 255, 0, 255);
	}
	// 纵线
	for (int j = y - crossSize; j <= y + crossSize; j++) {
		gfx.PutPixel(x, j, 255, 0, 255);
	}
}


Game::Game( HWND hWnd,const KeyboardServer& kServer )
:	gfx ( hWnd ),
	kbd( kServer )
{}

void Game::Go() {
	gfx.BeginFrame(); 
	ComposeFrame();
	gfx.EndFrame();
}

void Game::ComposeFrame() {
	
	getCross(crossX, crossY);
	int move_x_Range = 0, move_y_Range = 0;

	if (kbd.UpIsPressed()) {
		// 上键
		move_y_Range -= 1;
	}
	if (kbd.DownIsPressed()) {
		// 下键
		move_y_Range += 1;
	}
	if (kbd.LeftIsPressed()) {
		// 左键
		move_x_Range -= 1;
	}
	if (kbd.RightIsPressed()) {
		// 右键
		move_x_Range += 1;
	}

	// 判断十字座标是否超过视窗范围
	if (crossX <= crossSize) {
		move_x_Range = 1;
		
	}
	if (crossY <= crossSize) {
		move_y_Range = 1;
	}
	if (crossX > windowsWidth - crossSize) {
		move_x_Range = -1;
	}
	if (crossY > windowsHeight - crossSize) {
		move_y_Range = -1;
	}

	// 更新十字中心点坐标
	crossX += move_x_Range;
	crossY += move_y_Range;

	// 移动后绘制
	getCross(crossX, crossY);
}

 