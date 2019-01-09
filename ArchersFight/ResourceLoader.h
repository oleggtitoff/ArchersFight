#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

#define text2 "Press \"Enter\" to skip"
#define text4 "'Right' - move right\n'Left' - move left\n   'S' - shield\n'Space' - to shoot"
#define text5 "Good luck!"
#define text6 "You win"
#define text7 "You lose"
#define text8 "        The end"

using namespace std;
using namespace sf;

class ResourceLoader	//loads all necessary files
{
private:
	ResourceLoader();
	static ResourceLoader *instance;
	bool successFlag;		//successful load flag
							//path to files:
	string fontPath = "source/arial.ttf";
	string backgroundPath = "source/ScreensaverTexture.jpg";
	string gameBackgroundPath = "source/GameTexture.jpg";
	string boxPath = "source/BoxTexture.jpg";
	string archerPath = "source/ArcherTexture.png";
	string shieldPath = "source/ShieldTexture.png";
	string arrowPath = "source/ArrowTexture.PNG";
	string music2Path = "source/03-Lydia.flac";
	string music3Path = "source/07. Black Honey.flac";

	Font font;
	Texture backgroundTexture;
	Texture gameBackgroundTexture;
	Texture boxTexture;
	Texture archerTexture;
	Texture shieldTexture;
	Texture arrowTexture;
	Music music2;
	Music music3;
public:
	static ResourceLoader *GetInstance();
	bool GetSuccessFlag();
	Font *GetFontPtr();
	Texture *GetBackgroundTexturePtr();
	Texture *GetGameBackgroundTexturePtr();
	Texture *GetBoxTexturePtr();
	Texture *GetArcherTexturePtr();
	Texture *GetShieldTexturePtr();
	Texture *GetArrowTexturePtr();
	Music *GetMusic2Ptr();
	Music *GetMusic3Ptr();
	~ResourceLoader();
};
