#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <map>

class TextureManager 
{
public:
	std::map<std::string, SDL_Texture*> m_textureMap;

	bool load(std::string fileName, std::string id);

	// �������� ���� �׸�
	void draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);

	// �������� �ִ� �׸�
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void clearFromTextureMap(std::string id);

	// �ν��ϼ� ���� ���� �Լ�
	static TextureManager* Instance();

private:
	TextureManager() {}		// �̱����� ���� ������ private���� ����

};
// type ����
typedef TextureManager TheTextureManager;