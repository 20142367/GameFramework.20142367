#include "Player.h"
#include "InputHandler.h"
#include "Game.h"
#include "PlayState.h"
#include "GameOverState.h"
#include "ClearState.h"

Uint32 startTime, currentTime;
const float coolTime = 400.0f;

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_numFrames = 2;
}

void Player::draw()
{
	SDLGameObject::draw(); // SDLGameObject의 draw함수를 사용
}

void Player::update()
{
	m_currentFrame = int((SDL_GetTicks() / 100) % m_numFrames);		// 스프라이트 이미지의 개수만큼 순환

	if (PlayState::Instance()->checkCollision(dynamic_cast<SDLGameObject*>(PlayState::Instance()->m_spawns[0]), dynamic_cast<SDLGameObject*>(PlayState::Instance()->m_players[0])))
	{
		if (PlayState::Instance()->getType())
			makeBody();
		else
			reduceBody();

		PlayState::Instance()->m_spawns.clear();
		PlayState::Instance()->feedcount = 0;
	}
	/*else if (PlayState::Instance()->checkCollision(dynamic_cast<SDLGameObject*>(PlayState::Instance()->m_spawns[0]), dynamic_cast<SDLGameObject*>(PlayState::Instance()->m_players[0])))
	{
		reduceBody();
		PlayState::Instance()->m_spawns.clear();
		PlayState::Instance()->feedcount = 0;
	}*/

	handleInput();	// 입력을 지속적으로 업데이트

	SDLGameObject::update();

	if (PlayState::Instance()->m_players.size() > 0)
	{
		if (PlayState::Instance()->checkUnCollision(dynamic_cast<SDLGameObject*>(PlayState::Instance()->m_players[0]), dynamic_cast<SDLGameObject*>(PlayState::Instance()->m_gameObjects[1])))		// 머리와 벽의 충돌 체크
		{
			TheGame::Instance()->getStateMachine()->changeState(GameOverState::Instance());
		}
	}

	for (int i = 1; i < PlayState::Instance()->m_players.size(); i++)
	{
		if (PlayState::Instance()->checkCollision(dynamic_cast<SDLGameObject*>(PlayState::Instance()->m_players[0]), dynamic_cast<SDLGameObject*>(PlayState::Instance()->m_players[i])))		// 머리와 몸통의 충돌 체크
		{
			TheGame::Instance()->getStateMachine()->changeState(GameOverState::Instance());
		}
	}
	clearcheck();

}

void Player::clean()
{
	bodycount = 0;
}

void Player::handleInput() 
{
	for (int i = bodycount; i > 0; i--)
	{
		PlayState::Instance()->m_players[i]->m_velocity.setX(PlayState::Instance()->m_players[i - 1]->m_velocity.getX());
		PlayState::Instance()->m_players[i]->m_velocity.setY(PlayState::Instance()->m_players[i - 1]->m_velocity.getY());
	}

	// 키보드 입력
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP) && !(PlayState::Instance()->m_players[0]->m_velocity.getY() > 0))
	{
		PlayState::Instance()->m_players[0]->m_velocity.setX(0);
		PlayState::Instance()->m_players[0]->m_velocity.setY(-30);
		PlayState::Instance()->m_players[0]->m_currentRow = 0;
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN) && !(PlayState::Instance()->m_players[0]->m_velocity.getY() < 0))
	{
		PlayState::Instance()->m_players[0]->m_velocity.setX(0);
		PlayState::Instance()->m_players[0]->m_velocity.setY(30);
		PlayState::Instance()->m_players[0]->m_currentRow = 2;
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT) && !(PlayState::Instance()->m_players[0]->m_velocity.getX() > 0))
	{
		PlayState::Instance()->m_players[0]->m_velocity.setX(-30);
		PlayState::Instance()->m_players[0]->m_velocity.setY(0);
		PlayState::Instance()->m_players[0]->m_currentRow = 1;
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT) && !(PlayState::Instance()->m_players[0]->m_velocity.getX() < 0))
	{
		PlayState::Instance()->m_players[0]->m_velocity.setX(30);
		PlayState::Instance()->m_players[0]->m_velocity.setY(0);
		PlayState::Instance()->m_players[0]->m_currentRow = 3;
	}


	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_Z))
	{
		startTime = SDL_GetTicks();

		if (coolTime <= startTime - currentTime)
		{
			if (m_velocity.getX() > 0)
			{
				Projectile* projectile = new Projectile(new LoaderParams(Player::m_position.getX() + 30, Player::m_position.getY() + 10, 32, 32, "tile"));
				PlayState::Instance()->m_tiles.push_back(projectile);
			}
			else if (m_velocity.getX() < 0)
			{
				Projectile* projectile = new Projectile(new LoaderParams(Player::m_position.getX() - 30, Player::m_position.getY() + 10, 32, 32, "tile"));
				PlayState::Instance()->m_tiles.push_back(projectile);
			}
			else if (m_velocity.getY() > 0)
			{
				Projectile* projectile = new Projectile(new LoaderParams(Player::m_position.getX() + 10, Player::m_position.getY() + 30, 32, 32, "tile"));
				PlayState::Instance()->m_tiles.push_back(projectile);
			}
			else if (m_velocity.getY() < 0)
			{
				Projectile* projectile = new Projectile(new LoaderParams(Player::m_position.getX() + 10, Player::m_position.getY() - 30, 32, 32, "tile"));
				PlayState::Instance()->m_tiles.push_back(projectile);
			}

			currentTime = SDL_GetTicks();
		}
	}
}

void Player::makeBody()
{
	if (PlayState::Instance()->m_players[bodycount]->m_velocity.getX() > 0)
	{
		body = new SDLGameObject(new LoaderParams(PlayState::Instance()->m_players[bodycount]->m_position.getX() - 30, PlayState::Instance()->m_players[bodycount]->m_position.getY(), 30, 30, "body"));
		PlayState::Instance()->m_players.push_back(body);
	}
	else if (PlayState::Instance()->m_players[bodycount]->m_velocity.getX() < 0)
	{
		body = new SDLGameObject(new LoaderParams(PlayState::Instance()->m_players[bodycount]->m_position.getX() + 30, PlayState::Instance()->m_players[bodycount]->m_position.getY(), 30, 30, "body"));
		PlayState::Instance()->m_players.push_back(body);
	}
	else if (PlayState::Instance()->m_players[bodycount]->m_velocity.getY() > 0)
	{
		body = new SDLGameObject(new LoaderParams(PlayState::Instance()->m_players[bodycount]->m_position.getX(), PlayState::Instance()->m_players[bodycount]->m_position.getY() - 30, 30, 30, "body"));
		PlayState::Instance()->m_players.push_back(body);
	}
	else if (PlayState::Instance()->m_players[bodycount]->m_velocity.getY() < 0)
	{
		body = new SDLGameObject(new LoaderParams(PlayState::Instance()->m_players[bodycount]->m_position.getX(), PlayState::Instance()->m_players[bodycount]->m_position.getY() + 30, 30, 30, "body"));
		PlayState::Instance()->m_players.push_back(body);
	}

	bodycount++;
}

void Player::reduceBody()
{
	if (bodycount > 0)
	{
		PlayState::Instance()->m_players.pop_back();

		bodycount--;
	}
}

void Player::checkHP()
{
	if (HP <= 0)
		TheGame::Instance()->getStateMachine()->changeState(GameOverState::Instance());
}

void Player::clearcheck()
{
	if (bodycount > 20)
		TheGame::Instance()->getStateMachine()->changeState(ClearState::Instance());
}