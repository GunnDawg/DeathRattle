#pragma once
#include "Texture.h"

class Animation
{
public:
	Animation(const char* filePath, unsigned int numFramesX, unsigned int numFramesY, double speed);
	~Animation()=default;

	void Load(unsigned int x, unsigned int y);
	inline void Unload() { m_Texture.Unload(); }
	void Play(double dt);
	inline void Start() { m_isPlaying = true; }
	inline void Stop() { m_isPlaying = false; }
	void Draw();

private:
	Texture m_Texture;

	unsigned int m_numFramesX      = 0;
	unsigned int m_numFramesY      = 0;
	unsigned int m_frameWidth      = 0;
	unsigned int m_frameHeight     = 0;
	unsigned int m_currentFrame    = 0;
	double m_animSpeed             = 0;
	double m_frameTime             = 0.0;
	const unsigned int m_FPS       = 60;

	bool m_isPlaying               = true;
};