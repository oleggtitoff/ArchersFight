#pragma once
#include "Screensaver2.h"

class Screensaver1 : public Screensaver2	//first screensaver
{
protected:
	Text inscription2;
	Text inscription3;
public:
	Screensaver1(Font *, Music *, Texture *, string, string, string, int, int, int);
	void DrawInscription(RenderWindow &);
	~Screensaver1() {}
};
