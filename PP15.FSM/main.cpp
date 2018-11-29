#include "Game.h"

const int FPS = 60;							// ���α׷��� �������� ����
const float DELAY_TIME = 1000.0f / FPS;		// ȭ�� ��� Ƚ���� ����
Uint32 frameStart, frameTime;

int main(int argc, char* argv[]) {

	std::cout << "game init attempt...\n";
	if (TheGame::Instance()->init("PP19.GameOverState", 100, 100, 640, 480, false))		// â ����(â �̸�, â x��ǥ, â y��ǥ, â�� ���α���, â�� ���α���, Ǯ��ũ�� ����)
	{
		std::cout << "game init success!\n";	// ����
	}
	else 
	{
		std::cout << "game init failure - " << SDL_GetError() << "\n";		// ����
		return -1;
	}

	while (TheGame::Instance()->running())
	{
		frameStart = SDL_GetTicks();
		TheGame::Instance()->handleEvents();
		TheGame::Instance()->update();
		TheGame::Instance()->render();
		frameTime = SDL_GetTicks() - frameStart;

		if (frameTime < DELAY_TIME)		// ���� �ѹ� ���� �ð��� ������ ������Ÿ�Ӻ��� ���ٸ� ���� �ð���ŭ �����̸� ������
		{
			SDL_Delay((int)(DELAY_TIME - frameTime));		// ���ڶ� ������ Ÿ�Ӹ�ŭ ������ ���� ��
		}
	}
	std::cout << "game closing...\n";
	TheGame::Instance()->clean();

	return 0;
}