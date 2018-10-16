//#include "Item.h"
//
//Item::Item(enum Type type) :
//m_xVel(0), m_yVel(0), m_speed(0),
//m_itemType(type),
//m_itemRect({0})
//{
//
//}
//
//Item::~Item()
//{
//	m_itemTexture.Unload();
//}
//
//void Item::Load(SDL_Renderer* passedRen)
//{
//	m_itemRect.x = 100;
//	m_itemRect.y = 100;
//	m_itemRect.w = 50;
//	m_itemRect.h = 50;
//
//	switch (m_itemType)
//	{
//		case Type::DamagePaddles:
//		{
//			m_itemTexture = Texture("Assets/Graphics/Items/item0.png");
//			m_itemTexture.Load(passedRen);
//		} break;
//
//		case Type::SwapPaddles:
//		{
//			m_itemTexture = Texture("Assets/Graphics/Items/item1.png");
//			m_itemTexture.Load(passedRen);
//		} break;
//
//		case Type::IncreaseSpeed:
//		{
//			m_itemTexture = Texture("Assets/Graphics/Items/item2.png");
//			m_itemTexture.Load(passedRen);
//		} break;
//
//		case Type::DecreaseSpeed:
//		{
//			m_itemTexture = Texture("Assets/Graphics/Items/item3.png");
//			m_itemTexture.Load(passedRen);
//		} break;
//
//		case Type::Health:
//		{
//			m_itemTexture = Texture("Assets/Graphics/Items/item4.png");
//			m_itemTexture.Load(passedRen);
//		} break;
//
//		default:
//			break;
//	}
//}
//
//void Item::Unload()
//{
//	m_itemTexture.Unload();
//}
//
//void Item::Draw(SDL_Renderer* passedRen)
//{
//	SDL_RenderCopy(passedRen, m_itemTexture.getTexture(), NULL, &m_itemRect);
//}
//
//void Item::Update(double dt)
//{
//	m_itemRect.y -= static_cast<int>(m_yVel * dt);
//}
//
//void Item::setType(Type x)
//{
//	m_itemType = x;
//}
//
//void Item::setPos(unsigned int x, unsigned int y)
//{
//	m_itemRect.x = x;
//	m_itemRect.y = y;
//}