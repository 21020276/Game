#include"MainMenu.h"
#include"Object.h"
#include<iostream>
using namespace std;
MainMenu::MainMenu()
{
    isClicked = false;
    //    Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
    //    gClick = Mix_LoadWAV("Clicked.wav");
    //glass.setSrc(0, 0, 1, 1);
    //glass.setDest(260, 470, 100, 100);
    
}

void MainMenu::Init(SDL_Renderer* ren)
{
    SoundOn.setSrc(0, 0, 160, 160);
    SoundOff.setSrc(0, 0, 160, 160);

    SoundOn.setDest(750, 565, 40, 40);
    SoundOff.setDest(750, 565, 40, 40);

    isClicked = false;
    menuBackGround = TextureManager::Texture("Image/Menu.jpg", ren);
    //glass.CreateTexture("Image/glass.png",ren);
    /*SoundOn.CreateTexture("Image/soundOn.png", ren);   
    SoundOff.CreateTexture("Image/soundOff.png", ren);*/
    
    
}

// Xử lý sự kiện
int MainMenu::EventHandling(SDL_Event& e, SDL_Renderer* ren)
{
    SDL_PollEvent(&e);
    if (e.type == SDL_QUIT) return -1;
    else
    {
        /*if (e.motion.x != 0)
            cout << e.motion.x << " " << e.motion.y << endl;*/
        if (e.type == SDL_MOUSEBUTTONDOWN) 
        {
            
            if (e.motion.x > 280 && e.motion.x < 525 && e.motion.y > 410 && e.motion.y < 510) isClicked = true;
            if (e.motion.x > 305 && e.motion.x < 500 && e.motion.y > 520 && e.motion.y < 580) return -1;
        }
    }
    return 0;
}

void MainMenu::Render(SDL_Renderer* ren)
{
    SDL_RenderClear(ren);
    SDL_RenderCopy(ren, menuBackGround, NULL, NULL);
    SDL_RenderPresent(ren);
}

bool MainMenu::getClicked()
{
    return isClicked;
}

MainMenu:: ~MainMenu()
{
    isClicked = false;
}
bool MainMenu::isSoundOn()
{
    if (getSoundOn % 2 == 0) return true;
    else
        return false;
}
void MainMenu::setClicked(bool flag)
{
    isClicked = flag;
}