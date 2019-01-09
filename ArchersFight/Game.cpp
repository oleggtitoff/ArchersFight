#include "Game.h"
#include <ctime>
#include <iostream>

Game::Game(Font *font, Texture *gameBackgroundTexture, Texture *boxTexture,
	Texture *archerTexture, Texture *shieldTexture, Texture *arrowTexture,
	string textWin, string textLose) : Background(gameBackgroundTexture)
{
	this->font = font;
	this->textWin = textWin;
	this->textLose = textLose;
	inscription.setFont(*(this->font));
	inscription.setCharacterSize(70);
	inscription.setFillColor(Color::Black);
	inscription.setOutlineThickness(3);
	inscription.setOutlineColor(Color::White);
	inscription.setStyle(Text::Bold);

	this->boxTexture = boxTexture;
	box1Sprite.setTexture(*(this->boxTexture));
	box2Sprite.setTexture(*(this->boxTexture));
	box1Sprite.setTextureRect(IntRect(0, 0, boxSize, boxSize));
	box2Sprite.setTextureRect(IntRect(0, 0, boxSize, boxSize));
	box1Sprite.setPosition((windowWidth / 2) - boxSize * 2, windowHeight - boxSize);
	box2Sprite.setPosition((windowWidth / 2) + boxSize, windowHeight - boxSize);

	archer1 = new Archer(archerTexture, shieldTexture,
		Vector2f(archerWidth, windowHeight - archerHeight), 1, playerSpeed);
	archer2 = new Archer(archerTexture, shieldTexture,
		Vector2f(windowWidth - archerWidth, windowHeight - archerHeight), 0, botSpeed);

	arrow1 = new Arrow(arrowTexture, arrowSpeed);
	arrow2 = new Arrow(arrowTexture, arrowSpeed);
	arrow3 = new Arrow(arrowTexture, arrowSpeed);
	arrow4 = new Arrow(arrowTexture, arrowSpeed);
	arrow5 = new Arrow(arrowTexture, arrowSpeed);
	arrow6 = new Arrow(arrowTexture, arrowSpeed);

	srand(time(0));
	clock.restart();
	lastBotShieldTime = clock.getElapsedTime();

	botDirection = 1;
	botCounter = 0;
	botShieldTime = 2;
}

bool Game::Update(RenderWindow &window)
{
	Event event;
	while (window.pollEvent(event))			//interception of user control
	{
		if ((event.type == Event::Closed) ||
			((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Escape)))
		{
			window.close();
			break;
		}

		if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::S))
		{
			archer1->ChangeShieldValue();
		}

		if (((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Space)) &&
			(clock.getElapsedTime().asSeconds() - archer1->GetLastShootTime().asSeconds() > reloadTime) &&
			(archer1->GetShieldValue() == false))
		{
			if (arrow1->GetIsAlive() == false)			//release an available arrow
				Shoot(archer1, arrow1, false);
			else if (arrow2->GetIsAlive() == false)
				Shoot(archer1, arrow2, false);
			else if (arrow3->GetIsAlive() == false)
				Shoot(archer1, arrow3, false);
		}
	}

	int tmp = ArrowUpdate();

	if (tmp == 1)
	{
		DrawWinMessage(window, true);
		return true;
	}
	else if (tmp == 2)
	{
		DrawWinMessage(window, false);
		return true;
	}

	BotLogic();
	PlayerMove();
	return false;
}

int Game::ArrowUpdate()				//returns whether someone has won
{
	if ((ArrowFlight(archer2, arrow1, false) == true) ||
		(ArrowFlight(archer2, arrow2, false) == true) ||
		(ArrowFlight(archer2, arrow3, false) == true))
	{
		return 1;
	}
	else if ((ArrowFlight(archer1, arrow4, true) == true) ||
		(ArrowFlight(archer1, arrow5, true) == true) ||
		(ArrowFlight(archer1, arrow6, true) == true))
	{
		return 2;
	}
	else
		return 0;
}

void Game::PlayerMove()						//player movement
{
	if (archer1->GetBounds().left < 0)
		archer1->Move(true);
	else if ((archer1->GetBounds()).intersects(box1Sprite.getGlobalBounds()))
		archer1->Move(false);

	if (Keyboard::isKeyPressed(Keyboard::Left))
		archer1->Move(false);

	if (Keyboard::isKeyPressed(Keyboard::Right))
		archer1->Move(true);
}

//realization of a shot
void Game::Shoot(Archer *archer, Arrow *arrow, bool isBot)
{
	archer->SetLastShootTime(clock.getElapsedTime());
	arrow->SetIsAlive(true);
	arrow->SetYSpeed(arrowSpeed);

	if (!isBot)
	{
		arrow->SetAngle(45);
		arrow->SetPosition(Vector2f(archer->GetBounds().left + archerWidth,
			archer->GetBounds().top));
	}
	else
	{
		arrow->SetAngle(315);
		arrow->SetPosition(Vector2f(archer->GetBounds().left,
			archer->GetBounds().top));
	}

}

//the logic of the arrow's flight
bool Game::ArrowFlight(Archer *enemy, Arrow *arrow, bool isBot)
{
	if (arrow->GetIsAlive() == true)
	{
		arrow->SetYSpeed(arrow->GetYSpeed() - 0.25);

		if (!isBot)
			arrow->SetAngle(arrow->GetAngle() + 1.25);
		else
			arrow->SetAngle(arrow->GetAngle() - 1.25);

		if (windowHeight - arrow->GetBounds().top - arrowHeight > 0)
		{
			if ((arrow->GetBounds().intersects(enemy->GetShieldBounds())) &&
				(enemy->GetShieldValue() == true))
			{
				arrow->SetIsAlive(false);
			}
			else
			{
				if (arrow->GetBounds().intersects(enemy->GetBounds()))
					return true;
				else
				{
					if (!isBot)
						arrow->Move(arrowSpeed);
					else
						arrow->Move(-arrowSpeed);
				}
			}
		}
		else
			arrow->SetIsAlive(false);
	}

	return false;
}

void Game::BotLogic()						//bot behavior logic
{
	if (clock.getElapsedTime().asSeconds() - lastBotShieldTime.asSeconds() > botShieldTime)
	{
		BotShieldTimeGenerator();
	}

	if ((botCounter <= 0) && (clock.getElapsedTime().asSeconds() - lastBotMove.asSeconds() > 0.3))
	{
		BotMoveCounterGenerator();
	}

	if ((clock.getElapsedTime().asSeconds() -
		archer2->GetLastShootTime().asSeconds() > reloadTime) &&
		(archer2->GetShieldValue() == false))
	{
		if (arrow4->GetIsAlive() == false)
			Shoot(archer2, arrow4, true);
		else if (arrow5->GetIsAlive() == false)
			Shoot(archer2, arrow5, true);
		else if (arrow6->GetIsAlive() == false)
			Shoot(archer2, arrow6, true);
	}

	if (botCounter == 0)
	{
		lastBotMove = clock.getElapsedTime();
		botCounter = -1;
	}
	else if (botCounter > 0)
	{
		if (botDirection == 1)
			archer2->Move(true);
		else if (botDirection == 0)
			archer2->Move(false);
	}

	botCounter--;
}

void Game::BotMoveCounterGenerator()	//random generator for the bot movement
{
	botDirection = !botDirection;

	if (botDirection == 0)
		botCounter = (rand() % int(archer2->GetBounds().left -
		(windowWidth / 2) - (boxSize * 2))) / botSpeed;
	else if (botDirection == 1)
		botCounter = (rand() % int(windowWidth -
			archer2->GetBounds().left - archerWidth)) / botSpeed;
}

void Game::BotShieldTimeGenerator()		//random generator for bot's shield shifts
{
	archer2->ChangeShieldValue();
	lastBotShieldTime = clock.getElapsedTime();

	if (archer2->GetShieldValue() == true)
		botShieldTime = ((rand() % 30) + 5) / 5;
	else
		botShieldTime = ((rand() % 10) + 5) / 5;
}

void Game::Draw(RenderWindow &window)			//draw everything
{
	window.clear();
	Background::DrawBackground(window);
	window.draw(box1Sprite);
	window.draw(box2Sprite);
	archer1->Draw(window);
	archer2->Draw(window);
	arrow1->Draw(window);
	arrow2->Draw(window);
	arrow3->Draw(window);
	arrow4->Draw(window);
	arrow5->Draw(window);
	arrow6->Draw(window);
	window.display();
}

//victory or defeat message
void Game::DrawWinMessage(RenderWindow &window, bool win)
{
	Time tmp = clock.getElapsedTime();
	inscription.setPosition(525, 100);

	if (win == true)
		inscription.setString(textWin);
	else
		inscription.setString(textLose);

	while (clock.getElapsedTime().asSeconds() - tmp.asSeconds() < 3)
	{
		window.draw(inscription);
		window.display();
	}
}

Game::~Game()
{
	delete archer1;
	delete archer2;
	delete arrow1;
	delete arrow2;
	delete arrow3;
	delete arrow4;
	delete arrow5;
	delete arrow6;
}
