#include "Popup.h"
#include "Game.h"

Popup::Popup(unsigned int size, const char* text) :
m_size(size), m_Text(text)
{
	game = &Game::GetInstance();
	m_popupText = Text(m_size, m_Text);
}

Popup::~Popup()
{
	game = nullptr;
}

void Popup::Load()
{

}

void Popup::Update()
{
	m_popupText.mTextRect.y += (m_slideSpeed * game->avgDeltaTime);
	//if (m_popupText.mTextRect.y > game->screenHeight)
	//{
	//	m_isActive = false;
	//}
}

void Popup::Draw()
{
	m_popupText.Draw(400, 400, 45);
}