#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

#define arrowWidth 5
#define arrowHeight 32

class Arrow		//arrow class
{
private:
	Texture *arrowTexture;
	Sprite arrowSprite;
	bool isAlive;			//flag whether the arrow is now released
	float ySpeed;
public:
	Arrow(Texture *, float);
	bool GetIsAlive();
	FloatRect GetBounds();		//arrow sprite bounds
	float GetAngle();
	float GetYSpeed();
	void SetIsAlive(bool);
	void SetPosition(Vector2f);
	void Move(float);
	void SetAngle(float);
	void SetYSpeed(float);
	void Draw(RenderWindow &);
	~Arrow() {}
};
