#pragma once
#include "Texture.h"

class Game;

class Animation
{
public:
	Animation()=default;
	Animation(const char* filePath, unsigned int numFramesX, unsigned int numFramesY, double speed);

	void Load(unsigned int x, unsigned int y, unsigned int w, unsigned int h);
	void Play(double dt);
	void Draw();
	inline void Start() { mIsPlaying = true; }
	inline void Stop() { mIsPlaying = false; }
	inline void Unload() { mTexture.Unload(); }

private:
	Game* game                           = nullptr;

	Texture mTexture;
	SDL_Rect mCropRect                  = { };
	SDL_Rect mPosRect                   = { };

	const unsigned int mNumFramesX      = 0;
	const unsigned int mNumFramesY      = 0;
	unsigned int mFrameWidth            = 0;
	unsigned int mFrameHeight           = 0;
	unsigned int mCurrentFrame          = 0;
	const double mAnimSpeed             = 0;
	double mFrameTime                   = 0.0;

	bool mIsPlaying                     = true;
};