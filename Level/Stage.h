//#pragma once
//extern "C"
//{
//	#include <SDL.h>
//}
//
//#include <array>
//#include "Graphics/Texture.h"
//#include "Graphics/Animation.h"
//
//class Game;
//
//class Stage
//{
//public:
//	Stage();
//	~Stage();
//
//	void Load();
//	void Unload();
//	void Update();
//	void Draw();
//
//private:
//	Game* game                                    = nullptr;
//
//	Texture m_Texture                             = Texture("Assets/Graphics/Stage/dungeon.png");
//	std::array<Animation, 2> m_Flames             = { Animation("Assets/Graphics/Animations/flames.png", 8, 4, 16.00),
//									                  Animation("Assets/Graphics/Animations/flames.png", 8, 4, 16.00) };
//};