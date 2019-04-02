#include <SDL_image.h>

#include "Texture.h"
#include "Game.h"

Texture::Texture(const std::string_view filePath) :
mFilePath(filePath.data())
{
	game = &Game::GetInstance();
}

void Texture::Load()
{
	mTexture = IMG_LoadTexture(game->Renderer, mFilePath.c_str());
	if (mTexture == nullptr)
	{
		GUNN_CORE_ERROR("TEXTURE: Error loading texture file: {0}. Error: {1}", mFilePath, IMG_GetError());
	}
	else
	{
		if (SDL_QueryTexture(mTexture, nullptr, nullptr, &mTextureRect.w, &mTextureRect.h) == -1)
		{
			GUNN_CORE_ERROR("TEXTURE: {0} is invalid. Error: {1}", mFilePath, IMG_GetError());
		}
		else
		{
			GUNN_CORE_INFO("TEXTURE LOADED: {0}", mFilePath);
		}
	}
}

void Texture::Unload()
{
	if (mTexture != nullptr)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = nullptr;
		GUNN_CORE_INFO("TEXTURE UNLOADED: {0}", mFilePath);
	}
}

void Texture::setRect(unsigned int x, unsigned int y, unsigned int w, unsigned int h)
{
	mTextureRect.x = x;
	mTextureRect.y = y;
	mTextureRect.w = w;
	mTextureRect.h = h;
}

void Texture::setRect(unsigned int x, unsigned int y)
{
	mTextureRect.x = x;
	mTextureRect.y = y;
}