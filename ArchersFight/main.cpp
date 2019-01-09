#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#include "ResourceLoader.h"
#include "Screensaver1.h"
#include "Game.h"

int main()
{
	ResourceLoader *loader = ResourceLoader::GetInstance();

	if (loader->GetSuccessFlag() == true)	//if the files are loaded successfully
	{
		int gamePart = 1;

		RenderWindow window(VideoMode(windowWidth, windowHeight), "Archers battle");
		window.setVerticalSyncEnabled(true);

		Screensaver1 manual(loader->GetFontPtr(), loader->GetMusic2Ptr(),
			loader->GetBackgroundTexturePtr(), text4, text2, text5, 58, 44, 36);

		Game game(loader->GetFontPtr(), loader->GetGameBackgroundTexturePtr(), 
			loader->GetBoxTexturePtr(), loader->GetArcherTexturePtr(), 
			loader->GetShieldTexturePtr(), loader->GetArrowTexturePtr(), text6, text7);

		Screensaver2 screensaver2(loader->GetFontPtr(), loader->GetMusic3Ptr(), 
			loader->GetBackgroundTexturePtr(), text8, 70);

		while (window.isOpen())
		{
			if (gamePart == 1)		//screensaver with instruction
			{
				manual.Show(window);
				gamePart = 2;
			}
			else if (gamePart == 2)		//game
			{
				if (game.Update(window) == true)
					gamePart = 3;

				game.Draw(window);
			}
			else if (gamePart == 3)		//final screensaver
			{
				screensaver2.Show(window);
				window.close();
			}
		}
	}
	
	return 0;
}
