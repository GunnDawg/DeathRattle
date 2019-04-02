#include "Sound.h"
#include "Log/Log.h"

Sound::Sound(const char* filePath) : 
mSoundFilePath(filePath)
{
	
}

void Sound::Load()
{
	mChunk = Mix_LoadWAV(mSoundFilePath);
	if (mChunk == nullptr)
	{
		GUNN_CORE_ERROR("Error loading audio file: {0}. Error: {1}", mSoundFilePath, Mix_GetError());
	}
	else
	{
		GUNN_CORE_INFO("SOUND LOADED: {0}", mSoundFilePath);
	}
}

void Sound::Unload()
{
	if (mChunk != nullptr)
	{
		Mix_FreeChunk(mChunk);
		mChunk = nullptr;
		GUNN_CORE_INFO("SOUND UNLOADED: {0}", mSoundFilePath);
	}
}

void Sound::setVolume(int v) const
{
	assert(v > 0 && "Volume cannot be divided by 0");
	Mix_VolumeChunk(mChunk, MIX_MAX_VOLUME / v);
}