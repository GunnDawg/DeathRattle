#pragma once
#include <array>
#include "StateMachine/GameState.h"
#include "Graphics/Texture.h"
#include "Graphics/Animation.h"

class PauseScene : public GameState
{
public:
	void on_enter() override;
	void on_exit() override;
	void update() override;
	void handle_events() override;
	void draw() override;

private:
	Texture m_background                 = Texture("Assets/Graphics/common/main_background.png");
	std::array<Animation, 2> m_Flames    = { Animation("Assets/Graphics/Animations/flames.png", 8, 4, 16.00),
									         Animation("Assets/Graphics/Animations/flames.png", 8, 4, 16.00) };
};