#include "Game.h"

const int FPS = 60;							// 프로그램의 프레임을 설정
const float DELAY_TIME = 1000.0f / FPS;		// 화면 출력 횟수를 조절
Uint32 frameStart, frameTime;

int main(int argc, char* argv[]) {

	std::cout << "game init attempt...\n";
	if (TheGame::Instance()->init("PP19.GameOverState", 100, 100, 640, 480, false))		// 창 생성(창 이름, 창 x좌표, 창 y좌표, 창의 가로길이, 창의 세로길이, 풀스크린 여부)
	{
		std::cout << "game init success!\n";	// 성공
	}
	else 
	{
		std::cout << "game init failure - " << SDL_GetError() << "\n";		// 실패
		return -1;
	}

	while (TheGame::Instance()->running())
	{
		frameStart = SDL_GetTicks();
		TheGame::Instance()->handleEvents();
		TheGame::Instance()->update();
		TheGame::Instance()->render();
		frameTime = SDL_GetTicks() - frameStart;

		if (frameTime < DELAY_TIME)		// 루프 한번 도는 시간이 설정한 딜레이타임보다 적다면 남은 시간만큼 딜레이를 시켜줌
		{
			SDL_Delay((int)(DELAY_TIME - frameTime));		// 모자란 딜레이 타임만큼 딜레이 시켜 줌
		}
	}
	std::cout << "game closing...\n";
	TheGame::Instance()->clean();

	return 0;
}