#include "Background.h"

Background::Background(Texture *backgroundTexture)
{
	this->backgroundTexture = backgroundTexture;
	backgroundSprite.setTexture(*(this->backgroundTexture));
	backgroundSprite.setTextureRect(IntRect(0, 0, windowWidth, windowHeight));
}

void Background::DrawBackground(RenderWindow &window)
{
	window.draw(backgroundSprite);
}
