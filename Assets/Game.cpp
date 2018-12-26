
//	Game.cpp																		

#include "Game.h"
#include <iostream>

#define crossSize 5
#define windowsHeight 600
#define windowsWidth 700

int crossX = windowsWidth / 2, crossY = windowsHeight / 2;

// ����ʮ�ֹ�꣬������ʮ�����ĵ�����
void Game::getCross(int x, int y) {
	// ����
	for (int i = x - crossSize; i <= x + crossSize; i++) {
		gfx.PutPixel(i, y, 255, 0, 255);
	}
	// ����
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
		// �ϼ�
		move_y_Range -= 1;
	}
	if (kbd.DownIsPressed()) {
		// �¼�
		move_y_Range += 1;
	}
	if (kbd.LeftIsPressed()) {
		// ���
		move_x_Range -= 1;
	}
	if (kbd.RightIsPressed()) {
		// �Ҽ�
		move_x_Range += 1;
	}

	// �ж�ʮ�������Ƿ񳬹��Ӵ���Χ
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

	// ����ʮ�����ĵ�����
	crossX += move_x_Range;
	crossY += move_y_Range;

	// �ƶ������
	getCross(crossX, crossY);
}

 