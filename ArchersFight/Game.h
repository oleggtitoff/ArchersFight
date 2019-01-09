#pragma once
#include "Background.h"
#include "Arrow.h"
#include "Archer.h"
#include <string>
using std::string;

#define boxSize 90
#define playerSpeed 5
#define botSpeed 3
#define arrowSpeed 10
#define reloadTime 1

class Game : public Background
{
private:
	Font *font;
	string textWin;
	string textLose;
	Text inscription;
	Texture *boxTexture;
	Texture *arrowTexture;
	Sprite box1Sprite;
	Sprite box2Sprite;
	Archer *archer1;
	Archer *archer2;
	Arrow *arrow1;
	Arrow *arrow2;
	Arrow *arrow3;
	Arrow *arrow4;
	Arrow *arrow5;
	Arrow *arrow6;
	int botDirection;			//current direction of the bot
	int botCounter;
	int botShieldTime;
	Clock clock;
	Time lastBotMove;
	Time lastBotShieldTime;
public:
	Game(Font *, Texture *, Texture *, Texture *, Texture *, Texture *, string, string);
	bool Update(RenderWindow &);
	int ArrowUpdate();
	void PlayerMove();
	void Shoot(Archer *, Arrow *, bool);
	bool ArrowFlight(Archer *, Arrow *, bool);
	void BotLogic();
	void BotMoveCounterGenerator();
	void BotShieldTimeGenerator();
	void Draw(RenderWindow &);
	void DrawWinMessage(RenderWindow &, bool);
	~Game();
};
