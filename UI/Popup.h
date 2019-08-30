#pragma once
#include "Text.h"

class Game;

class Popup
{
public:
	Popup(unsigned int size, const char* text);
	~Popup();

	void Load();
	void Unload();
	void Update();
	void Draw();

	inline void setActive(bool active) { m_isActive = active; }
	inline bool isActive() const { return m_isActive; }

private:
	Game* game                          = nullptr;

	Text m_popupText;
	unsigned int m_size                 = 0;
	const char* m_Text                  = { };
	unsigned int m_duration             = 0;
	double m_rotation                   = 0.0;
	double m_slideSpeed                 = 0.50;

	bool m_isActive                     = false;
};