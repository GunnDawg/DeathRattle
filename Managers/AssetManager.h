#pragma once
#include <SDL.h>
#include <cstdio>

#include "../Graphics/Texture.h"

class AssetManager
{
public:
	static AssetManager& getInstance()
	{
		static AssetManager instance;
		return instance;
	}

	AssetManager(AssetManager const&) = delete;
	void operator=(AssetManager const&) = delete;
	~AssetManager();

	template<typename T>
	static T CreateAsset(T& asset);

private:
	AssetManager() { };
};