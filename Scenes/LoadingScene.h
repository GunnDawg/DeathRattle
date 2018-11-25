#pragma once
#include <memory>
#include "StateMachine/GameState.h"
#include "Graphics/Texture.h"
#include "Graphics/Animation.h"
#include "Time/Timer.h"

class LoadingScene : public GameState
{
public:
	void on_enter() override;
	void on_exit() override;
	void update() override;
	void handle_events() override;
	void draw() override;

private:
	Timer m_timer;
	Texture m_Loading              = Texture("Assets/Graphics/loading_scene/loading.png");
};