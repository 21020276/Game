#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "TextureManager.h"
#include "MainMenu.h"
#include "Player.h"
#include <iostream>
#include <vector>

#include<string>

class Controler
{
    const int HEIGHT = 600;
    const int WIDTH = 800;
    const int MAXN = 5000;
    int score = 0;
    int j = 0;
    int leftNum = 0;
    int score_ = 0;
    int secondScore = 0;
    unsigned int highscore = 0;
    bool isClicked = false;
    bool isOver;
    bool Continue;
    bool flag = false;
    long long Time = 0;
    bool firstAction;
    bool exit;
    
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;

    TTF_Font* font = NULL;
    SDL_Color color = { 255,255,255 };
    SDL_Surface* surfaceMessage = NULL;
    SDL_Texture* Message = NULL;
    SDL_Rect Message_rect;
    
    
    MainMenu Menu;
    
    

    Player Bird;
    
    
    Object Point[10];
    Object Background;
    Object Mess;
    Object Over;
    Object Score;
    Object BronzeMedal, SilverMedal, GoldMedal, Medal;
    Object SoundOn, SoundOff;
    
    struct Node
    {
        int x, y, h, w;
    }blockU[5000], blockD[5000];

    Mix_Chunk* gMusic;
    Mix_Chunk* click;
    Mix_Chunk* die;
    Mix_Chunk* hit;
    Mix_Chunk* point;
    Object BU, BD;

public:
    Controler();
    bool playAgain();
    bool getContinue();
    void Init();
    void Event();
    void Update();
    void sendmess();
    void Render();
    void Clear();
    void GenBlock();
    void MainMenu();
    void GameOver();
    void WaitUltilKeyPress();
    int reverse(int point);
    void printScore();
    bool Check(Node a, Node b);
    bool getClicked();
    void setClicked(bool flags);
    void reset();
    bool getFirstAction();
    bool exitGame();
};