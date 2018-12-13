#include "TextureManager.h"
#include "Game.h"

bool TextureManager::load(std::string fileName, std::string id)		// 이미지 로드 함수
{
	SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());

	if (pTempSurface == 0) {
		return false;
	}

	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(TheGame::Instance()->getRenderer(), pTempSurface);
	SDL_FreeSurface(pTempSurface);

	if (pTexture != 0) {
		m_textureMap[id] = pTexture;
		return true;
	}

	return false;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip)		// 이미지 드로우 함수(프레임x)
{
	SDL_Rect srcRect;	// 원본 사각형
	SDL_Rect destRect;	// 대상 사각형

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(TheGame::Instance()->getRenderer(), m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_RendererFlip flip)		// 스프라이트 이미지 드로우 함수(프레임o)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = width * currentFrame;
	srcRect.y = height * currentRow;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(TheGame::Instance()->getRenderer(), m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::clearFromTextureMap(std::string id)		// 이미지 클리어
{
	m_textureMap.erase(id);
}

TextureManager* TextureManager::Instance()		// 생성자 접근을 위한 변수 s_pInstance를 한개만 생성(싱글톤)
{
	static TextureManager* s_pInstance;

	if (s_pInstance == 0)
	{
		s_pInstance = new TextureManager();
		return s_pInstance;
	}
	return s_pInstance;
}