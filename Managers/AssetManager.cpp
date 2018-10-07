#include "AssetManager.h"

template<typename T>
T AssetManager::CreateAsset(T& asset)
{
	switch (asset)
	{
		case Texture:
		{
			Texture tex = Texture();

			return tex;
		} break;
	}
}