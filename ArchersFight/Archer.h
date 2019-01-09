#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

#define archerWidth 65
#define archerHeight 98
#define shieldWidth 9
#define shieldHeight 74

class Archer		//archer class
{
private:
	Texture *archerTexture;
	Texture *shieldTexture;
	Sprite archerSprite;
	Sprite shieldSprite;
	float speed;
	bool shield;			//is there a shield now
	Time lastShootTime;
public:
	Archer(Texture *, Texture *, Vector2f, bool, float);
	FloatRect GetBounds();		//archer sprite bounds
	FloatRect GetShieldBounds();	//shield sprite bounds
	bool GetShieldValue();
	Time GetLastShootTime();
	void ChangeShieldValue();
	void SetLastShootTime(Time);
	void Move(bool);
	void Draw(RenderWindow &);
	~Archer() {}
};
