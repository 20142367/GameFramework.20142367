#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <map>

class TextureManager 
{
public:
	std::map<std::string, SDL_Texture*> m_textureMap;

	bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);

	// 프레임이 없는 그림
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	// 프레임이 있는 그림
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void clearFromTextureMap(std::string id);

	// 인스턴수 변수 생성 함수
	static TextureManager* Instance();

private:
	TextureManager() {}		// 싱글톤을 위해 생성자 private으로 설정
};
// type 설정
typedef TextureManager TheTextureManager;