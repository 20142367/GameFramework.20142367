#include "Player.h"

/*
// GameObject - Player(상속관계)관계에서 Player에 변경하지 않은것은 GameObject에서 실행되기 때문에 특별히 변경해줄 것만 Player에 선언해주면 됨
void Player::load(int x, int y, int width, int height,
	std::string textureID)
{
	// GameObject::load(x, y, width, height, textureID);
	// 이 코드가 의미가 있을까? 이코드가 없었다면, 자동으로 부모 호출?? 
}

void Player::draw(SDL_Renderer* pRenderer)
{
	// GameObject::draw(pRenderer);
	// 이 코드가 의미가 있을까? 이코드가 없었다면, 자동으로 부모 호출?? 
}*/

void Player::update()
{
	m_x -= 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}