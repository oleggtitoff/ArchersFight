#include "Arrow.h"

Arrow::Arrow(Texture *arrowTexture, float xSpeed)
{
	isAlive = false;
	this->ySpeed = xSpeed;
	this->arrowTexture = arrowTexture;
	arrowSprite.setTexture(*(this->arrowTexture));
	arrowSprite.setTextureRect(IntRect(0, 0, arrowWidth, arrowHeight));
}

bool Arrow::GetIsAlive()		//flag whether the arrow is now released
{
	return isAlive;
}

FloatRect Arrow::GetBounds()		//arrow sprite bounds
{
	return arrowSprite.getGlobalBounds();
}

float Arrow::GetAngle()				//current angle of the arrow
{
	return arrowSprite.getRotation();
}

float Arrow::GetYSpeed()			//current Y speed
{
	return ySpeed;
}

void Arrow::SetIsAlive(bool isAlive)
{
	this->isAlive = isAlive;
}

void Arrow::SetPosition(Vector2f position)
{
	arrowSprite.setPosition(position);
}

void Arrow::Move(float x)
{
	arrowSprite.move(x, -ySpeed);
}

void Arrow::SetAngle(float angle)
{
	arrowSprite.setRotation(angle);
}

void Arrow::SetYSpeed(float ySpeed)
{
	this->ySpeed = ySpeed;
}

void Arrow::Draw(RenderWindow &window)		//drawing an arrow
{
	if (isAlive == true)
		window.draw(arrowSprite);
}
