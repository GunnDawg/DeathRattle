#pragma once
#include "Texture.h"

class Animation
{
public:
	Animation(const char* filePath, unsigned int numFramesX, unsigned int numFramesY);
	~Animation()=default;

	void Load(unsigned int x, unsigned int y);
	void Play(double dt);
	void Stop();
	void Draw();
	void Update(unsigned int x, unsigned int y);

private:
	Texture m_Texture;

	unsigned int m_numFramesX      = 0;
	unsigned int m_numFramesY      = 0;
	unsigned int m_frameWidth      = 0;
	unsigned int m_frameHeight     = 0;
	unsigned int m_currentFrame    = 0;
	double m_frameTime    = 0.0;
	const unsigned int m_FPS       = 60;
};