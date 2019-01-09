#include "ResourceLoader.h"
#include <iostream>

ResourceLoader *ResourceLoader::instance = nullptr;

ResourceLoader::ResourceLoader()
{
	if ((!font.loadFromFile(fontPath)) || (!backgroundTexture.loadFromFile(backgroundPath)) ||
		(!gameBackgroundTexture.loadFromFile(gameBackgroundPath)) ||
		(!boxTexture.loadFromFile(boxPath)) || (!archerTexture.loadFromFile(archerPath)) ||
		(!arrowTexture.loadFromFile(arrowPath)) || (!shieldTexture.loadFromFile(shieldPath)) ||
		(!music2.openFromFile(music2Path)) || (!music3.openFromFile(music3Path)))
	{
		cout << "Error! Loading source files failed.\n";
		successFlag = false;
	}
	else
		successFlag = true;
}

ResourceLoader *ResourceLoader::GetInstance()	//realization of singleton
{
	if (instance == nullptr)
		instance = new ResourceLoader;

	return instance;
}

bool ResourceLoader::GetSuccessFlag()		//whether all media files loaded successfully
{
	return successFlag;
}

Font *ResourceLoader::GetFontPtr()
{
	return &font;
}

Texture *ResourceLoader::GetBackgroundTexturePtr()
{
	return &backgroundTexture;
}

Texture *ResourceLoader::GetGameBackgroundTexturePtr()
{
	return &gameBackgroundTexture;
}

Texture *ResourceLoader::GetBoxTexturePtr()
{
	return &boxTexture;
}

Texture *ResourceLoader::GetArcherTexturePtr()
{
	return &archerTexture;
}

Texture *ResourceLoader::GetShieldTexturePtr()
{
	return &shieldTexture;
}

Texture *ResourceLoader::GetArrowTexturePtr()
{
	return &arrowTexture;
}

Music *ResourceLoader::GetMusic2Ptr()
{
	return &music2;
}

Music *ResourceLoader::GetMusic3Ptr()
{
	return &music3;
}

ResourceLoader::~ResourceLoader()
{
	delete instance;
}