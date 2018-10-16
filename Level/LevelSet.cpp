#include "LevelSet.h"
#include "Game.h"

LevelSet::LevelSet(const char* filePath, unsigned int w, unsigned int h) :
m_levelTextures({}),
m_levelScore({0}), m_levelNum(0),
m_cached(false)
{
	assert(typeid(filePath) == typeid(const char*) && filePath > 0);
	assert(typeid(w) == typeid(unsigned int) && w > 0);
	assert(typeid(h) == typeid(unsigned int) && h > 0);

	for (size_t i = 0; i < m_levelTextures.size(); ++i)
	{
		std::ostringstream out;
		out << filePath << "level" << i << ".png";
		std::string filename = out.str();
		m_levelTextures[i].Load(filename);
		m_levelTextures[i].setRect(0, 0, w, h);
	}
}

LevelSet::~LevelSet()
{
	UnloadAll();
}

void LevelSet::Load()
{
	//m_levelTextures[m_levelNum].Load("Assets/Graphics/Levels/Dungeon/");
}

void LevelSet::LoadAll()
{
	for (size_t i = 0; i < m_levelTextures.size(); ++i)
	{
		m_levelTextures[i].Load("Assets/Graphics/Levels/Dungeon/");
	}
}

void LevelSet::Unload(int x)
{
	m_levelTextures[x].Unload();
}

void LevelSet::UnloadAll()
{
	for (size_t i = 0; i < m_levelTextures.size(); ++i)
	{
		if (m_levelTextures[i].getTexture() != nullptr)
		{
			m_levelTextures[i].Unload();
		}
	}
}

void LevelSet::setScores(std::array<int, LEVEL_COUNT> s)
{
	for (size_t i = 0; i < s.size(); ++i)
	{
		m_levelScore[i] = s[i];
	}
}

void LevelSet::Draw()
{
	SDL_Rect rect = m_levelTextures[m_levelNum].m_TextureRect;
	SDL_RenderCopy(Game::Renderer, m_levelTextures[m_levelNum].m_Texture, nullptr, &rect);
}

void LevelSet::setLevel(unsigned int x)
{
	m_levelNum = x;
}

void LevelSet::nextLevel(bool v)
{
	if (m_levelNum < (m_levelTextures.size() - 1) && !v)
	{
		Unload(m_levelNum);
		++m_levelNum;
		Load();
	}
	else if (m_levelNum < (m_levelTextures.size() - 1))
	{
		++m_levelNum;
	}
	else
	{
		if (!v)
		{
			Unload(m_levelNum);
			m_levelNum = 0;
			Load();
		}
		else
		{
			m_levelNum = 0;
		}
	}
}

void LevelSet::prevLevel()
{
	if (m_levelNum >= 1)
	{
		Unload(m_levelNum);
		--m_levelNum;
		Load();
	}
}