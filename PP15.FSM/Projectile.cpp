#include "Projectile.h"
#include "Vector2D.h"
#include "Player.h"
#include "Game.h"
#include "PlayState.h"
#include "TextureManager.h"

Projectile::Projectile(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_velocity.setX(2);
}

void Projectile::draw()
{
	SDLGameObject::draw();
}

void Projectile::update()
{
	m_position += m_velocity;
}

void Projectile::clean()
{
	TheTextureManager::Instance()->clearFromTextureMap("tile");
}

void Projectile::Frame(int change)
{
	this->m_currentFrame = change;
}