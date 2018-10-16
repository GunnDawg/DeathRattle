//#pragma once
//#include <cassert>
//#include <cstdio>
//#include <memory>
//#include <array>
//#include <sstream>
//#include "Graphics/Texture.h"
//
//enum class Type{ DamagePaddles, SwapPaddles, IncreaseSpeed, DecreaseSpeed, Health };
//
//class Item
//{
//public:
//	Item()=default;
//	Item(enum Type type);
//	~Item();
//
//	void Load(SDL_Renderer* passedRen);
//	void Unload();
//	void Draw(SDL_Renderer* passedRen);
//	void Update(double dt);
//	void setType(Type x);
//	void setPos(unsigned int x, unsigned int y);
//
//private:
//	//Item(const Item& obj)=delete;
//	//Item& operator=(const Item&)=delete;
//
//	float m_xVel;
//	float m_yVel;
//	float m_speed;
//
//	Texture m_itemTexture;
//	Type m_itemType;
//	SDL_Rect m_itemRect;
//};