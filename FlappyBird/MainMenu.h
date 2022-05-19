#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "TextureManager.h"
#include <stdio.h>
#include <string>
#include "Object.h"
class MainMenu
{
private:
    bool isClicked;
    SDL_Texture* menuBackGround;
    Object SoundOn,SoundOff;
    Object glass;
  
    int getSoundOn = 0;
public:
    MainMenu();
    ~MainMenu();
    bool isSoundOn();
    void Init(SDL_Renderer* ren);

    int EventHandling(SDL_Event& e, SDL_Renderer* ren);
    void Render(SDL_Renderer* ren);
    bool getClicked();
    void setClicked(bool flag);
};