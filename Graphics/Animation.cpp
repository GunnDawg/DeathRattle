#include "Animation.h"
#include "Game.h"

Animation::Animation(const char* filePath, unsigned int numFramesX, unsigned int numFramesY, double speed) :
mTexture(filePath),
mNumFramesX(numFramesX), mNumFramesY(numFramesY),
mAnimSpeed(speed)
{
	game = &Game::GetInstance();

	mTexture.Load();

	mFrameWidth = (mTexture.mTextureRect.w / mNumFramesX);
	mFrameHeight = (mTexture.mTextureRect.h / mNumFramesY);

	mCropRect.w = mFrameWidth;
	mCropRect.h = mFrameHeight;
}

void Animation::Load(unsigned int x, unsigned int y, unsigned int w, unsigned int h)
{
	mPosRect.x = x;
	mPosRect.y = y;
	mPosRect.w = w;
	mPosRect.h = h;
}

void Animation::Play(double dt)
{
	if (mIsPlaying)
	{
		mFrameTime += dt;
		if (mFrameTime >= mAnimSpeed)
		{
			mFrameTime = 0;
			mCropRect.x += mFrameWidth;
			if (mCropRect.x >= mTexture.mTextureRect.w)
			{
				mCropRect.x = 0;
				if (mNumFramesY > 1)
				{
					mCropRect.y += mFrameHeight;
					if (mCropRect.y >= mTexture.mTextureRect.h)
					{
						mCropRect.y = 0;
					}
				}
			}
		}
	}
	else
	{
		mFrameTime = 0.0;
		mCropRect.x = mFrameWidth;
	}
}

void Animation::Draw()
{
	SDL_RenderCopy(game->Renderer, mTexture.mTexture, &mCropRect, &mPosRect);
}