#include"Control.h"
#include"MainMenu.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "TextureManager.h"

using namespace std;

TTF_Font* font1 = NULL;

int main(int argc,char** argv)
{
    enum Screen {MenuScreen, PlayScreen};
    Screen currentScreen = MenuScreen;
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        //success = false;
    }

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
                    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
                    //success = false;
    }

    Mix_Chunk* gMusic;
    Controler* game = new Controler();
    gMusic = Mix_LoadWAV("Sound/ingame.mp3");
    Mix_PlayChannel(-1, gMusic, -1);

    Mix_Volume(-1, 20);
    
    game->Init();
    
    long long time = 0;
    double first,last=0;
    bool isMusicPlaying = false;
    
    while(!game->exitGame())
    {
        time++;

        switch (currentScreen)
        {
        case MenuScreen:
            game->MainMenu();
            if (game->getClicked())
            {
                currentScreen = PlayScreen;
                /*if (!isMusicPlaying)
                {
                    Mix_PlayChannel(-1, gMusic, 0);
                    isMusicPlaying = true;
                }*/
                game->reset();
                game->GenBlock();
            }
            break;
        case PlayScreen:
            
            game->Event();

            game->Render();
            if (!game->getContinue())
            {
                /*isMusicPlaying = false;
                Mix_CloseAudio();*/
                game->setClicked(false);
                currentScreen = MenuScreen;
               
            }
            break;
        }
        
        first = SDL_GetTicks();
        
		if (first - last < 17)
		{
			SDL_Delay(17 - (first - last));
		}
		last = first;
        
    }
    
    game->Clear();

    return 0 ;

}
