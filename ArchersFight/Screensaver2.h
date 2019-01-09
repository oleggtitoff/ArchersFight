#pragma once
#include <SFML/Audio.hpp>
#include "Background.h"
#include <string>
using std::string;

//final screensaver
class Screensaver2 : public Background
{
protected:
	Font *font;
	Text inscription;
	Music *music;
public:
	Screensaver2(Font *, Music *, Texture *, string, int);
	virtual void DrawInscription(RenderWindow &);
	void Show(RenderWindow &);
	~Screensaver2() {}
};
