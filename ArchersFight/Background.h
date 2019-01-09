#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

#define windowWidth 1280
#define windowHeight 720

class Background	//displays the background
{
private:
	Texture *backgroundTexture;
	Sprite backgroundSprite;
public:
	Background(Texture *);
	void DrawBackground(RenderWindow &);
	~Background() {}
};
