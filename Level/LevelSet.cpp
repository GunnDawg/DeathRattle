#include "LevelSet.h"
#include "Game.h"

LevelSet::LevelSet(const char* filePath) :
m_levelTextures({ }),
m_levelScore({ 0 }),
m_levelNum(0)
{
	assert(typeid(filePath) == typeid(const char*) && filePath > 0);

	for (size_t i = 0; i < m_levelTextures.size(); i++)
	{
		std::ostringstream out;
		out << filePath << "level" << i << ".png";
		m_filename = out.str();
		m_levelTextures[i] = Texture(m_filename);
	}
}

LevelSet::~LevelSet()
{
	Unload(m_levelNum);
	printf("Levelset DTOR\n");
}

void LevelSet::Load()
{
	m_levelTextures[m_levelNum].Load();
	m_levelTextures[m_levelNum].setRect(0, 0, Game::screenWidth, Game::screenHeight);
}

void LevelSet::Unload(int x)
{
	m_levelTextures[x].Unload();
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

void LevelSet::nextLevel()
{
	if (m_levelNum < (m_levelTextures.size() - 1))
	{
		Unload(m_levelNum);
		++m_levelNum;
		Load();
	}
	else
	{
		Unload(m_levelNum);
		m_levelNum = 0;
		Load();
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