#include "Screensaver1.h"

Screensaver1::Screensaver1(Font *font, Music *music,
	Texture *backgroundTexture, string text1, string text2, string text3,
	int textSize1, int textSize2, int textSize3) :
	Screensaver2(font, music, backgroundTexture, text1, textSize1)
{
	inscription2.setFont(*(this->font));
	inscription2.setString(text2);
	inscription2.setCharacterSize(textSize2);
	inscription2.setFillColor(Color::Black);
	inscription2.setOutlineThickness(2);
	inscription2.setOutlineColor(Color::White);
	inscription2.setStyle(Text::Bold);
	inscription2.setPosition(460, 440);

	inscription3.setFont(*(this->font));
	inscription3.setString(text3);
	inscription3.setCharacterSize(textSize3);
	inscription3.setFillColor(Color::Red);
	inscription3.setOutlineThickness(2);
	inscription3.setOutlineColor(Color::White);
	inscription3.setStyle(Text::Bold);
	inscription3.setPosition(580, 620);
}

void Screensaver1::DrawInscription(RenderWindow &window)
{
	inscription.setPosition(420, 30);
	window.draw(inscription);
	window.draw(inscription2);
	window.draw(inscription3);
}
