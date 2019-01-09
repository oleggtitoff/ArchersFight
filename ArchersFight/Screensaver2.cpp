#include "Screensaver2.h"

Screensaver2::Screensaver2(Font *font, Music *music, Texture *backgroundTexture,
	string text, int textSize) : Background(backgroundTexture)
{
	this->music = music;
	this->font = font;
	inscription.setFont(*(this->font));
	inscription.setString(text);
	inscription.setCharacterSize(textSize);
	inscription.setFillColor(Color::Red);
	inscription.setOutlineThickness(2.5);
	inscription.setOutlineColor(Color::White);
	inscription.setStyle(Text::Bold);
}

void Screensaver2::DrawInscription(RenderWindow &window)
{
	inscription.setPosition(360, 280);
	window.draw(inscription);
}

void Screensaver2::Show(RenderWindow &window)		//music + background
{
	music->play();

	while (music->getStatus() == Music::Playing)
	{
		Event event;
		while (window.pollEvent(event))
		{
			if ((event.type == Event::Closed) ||
				((event.type == Event::KeyPressed) &&
				(event.key.code == Keyboard::Escape)))
			{
				music->stop();
				window.close();
				break;
			}
			else if ((event.type == Event::KeyPressed) &&
				(event.key.code == Keyboard::Return))
			{
				music->stop();
				break;
			}
		}

		window.clear();
		Background::DrawBackground(window);
		DrawInscription(window);
		window.display();
		sleep(milliseconds(100));
	}
}
