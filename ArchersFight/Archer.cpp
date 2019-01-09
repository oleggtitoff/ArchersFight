#include "Archer.h"

Archer::Archer(Texture *archerTexture, Texture *shieldTexture,
	Vector2f defaultPosition, bool spriteDirection, float speed)
{
	this->archerTexture = archerTexture;
	this->shieldTexture = shieldTexture;
	archerSprite.setTexture(*(this->archerTexture));
	shieldSprite.setTexture(*(this->shieldTexture));
	archerSprite.setTextureRect(IntRect(0, 0, archerWidth, archerHeight));
	shieldSprite.setTextureRect(IntRect(0, 0, shieldWidth, shieldHeight));

	if (!spriteDirection)			//mirror image of the archer
	{
		archerSprite.setScale(-1, 1);
		shieldSprite.setRotation(45);
	}
	else
		shieldSprite.setRotation(135);

	archerSprite.setPosition(defaultPosition);
	this->speed = speed;
	shield = false;
}

FloatRect Archer::GetBounds()				//archer sprite bounds
{
	return archerSprite.getGlobalBounds();
}

FloatRect Archer::GetShieldBounds()			//shield sprite bounds
{
	return shieldSprite.getGlobalBounds();
}

bool Archer::GetShieldValue()				//is there a shield now
{
	return shield;
}

Time Archer::GetLastShootTime()		//time of the last shot of an archer
{
	return lastShootTime;
}

void Archer::ChangeShieldValue()		//shifts the shield
{
	shield = !shield;
}

void Archer::SetLastShootTime(Time lastShootTime)
{
	this->lastShootTime = lastShootTime;
}

void Archer::Move(bool moveDirection)		//movement in a given direction
{
	if (moveDirection == false)
		archerSprite.move(-speed, 0);
	else if (moveDirection == true)
		archerSprite.move(speed, 0);
}

void Archer::Draw(RenderWindow &window)		//drawing an archer
{
	if (shield)								//with a shield	
	{
		archerSprite.setTextureRect(IntRect(archerWidth, 0, archerWidth, archerHeight));
		window.draw(archerSprite);

		if (archerSprite.getScale().x == 1)
			shieldSprite.setPosition(archerSprite.getPosition() + Vector2f(80, 40));
		else
			shieldSprite.setPosition(archerSprite.getPosition() - Vector2f(30, 10));

		window.draw(shieldSprite);
	}
	else									//without a shield
	{
		archerSprite.setTextureRect(IntRect(0, 0, archerWidth, archerHeight));
		window.draw(archerSprite);
	}
}
