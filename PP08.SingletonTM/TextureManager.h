#pragma once

#include <map>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

class TextureManager {

public:

	std::map<std::string, SDL_Texture*> m_textureMap;

	bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);

	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	
	// 함수 추가
	static TextureManager* Instance();

private :

	TextureManager() {}

};
// type  추가
typedef TextureManager TheTextureManager;