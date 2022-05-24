#include "Control.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
using namespace std;

Controler::Controler()
{
    window = NULL;
    renderer = NULL;
    reset();

};
void Controler::reset()
{   
    exit = false;
    Continue = true;
    isOver = false;
    firstAction = false;
    score = 0;

    Bird.Reset();
    Bird.setSrc(0, 0, 28, 38);
    Bird.setDest(200, HEIGHT / 2, 28, 38);

    Mess.setSrc(0, 0, 600, 400);
    Mess.setDest(200, 0, 600, 400);

    Over.setSrc(0, 0, 200, 400);
    Over.setDest(200, 0, 100, 400);

    Background.setSrc(0, 0, 600, 800);
    Background.setDest(0, 0, 600, 800);

    Score.setSrc(0, 0, 256, 503);
    Score.setDest(220, 200, 200, 393);

    BU.setSrc(0, 0, 400, 100);
    BD.setSrc(0, 0, 400, 100);

    BronzeMedal.setSrc(0, 0, 117, 108);
    BronzeMedal.setDest(260, 265, 90, 90);

    SilverMedal.setSrc(0, 0, 55, 53);
    SilverMedal.setDest(260, 265, 90, 90);

    GoldMedal.setSrc(0, 0, 74, 72);
    GoldMedal.setDest(260, 265, 90, 90);

    

    for (int i = 0; i < 10; i++)
        Point[i].setSrc(0, 0, 36, 24);
    Time = 0;

    click = Mix_LoadWAV("Sound/Clicked.wav");
    die = Mix_LoadWAV("Sound/die.wav");
    point = Mix_LoadWAV("Sound/point.wav");
    hit = Mix_LoadWAV("Sound/hit.wav");

 
}

void Controler::GenBlock()
{
    srand(time(0));
    // tao cot
    blockU[0].x = 500;
    blockU[0].y = 0;
    blockU[0].h = 200;
    blockU[0].w = 80;

    blockD[0].x = 500;
    blockD[0].y = 400;
    blockD[0].h = 200, 
    blockD[0].w = 80;

    for (int i = 1;i < MAXN;++i)
        blockU[i] = blockU[i - 1];
    
    for (int i = 0;i < MAXN;++i)
        blockU[i].h += rand() % 20 + 25;

    for (int i = 1;i < MAXN;++i)
        blockD[i] = blockD[i - 1];

    for (int i = 0;i < MAXN;++i)
    {
        blockD[i].y -= rand() % 20 + 25;
        blockD[i].h = 600 - blockD[i].y;
    }
    for (int i = 1;i < MAXN;++i)
    {
        int temp = rand() % 200;
        blockU[i].x = blockU[i - 1].x + 160 + temp;
        blockD[i].x = blockD[i - 1].x + 160 + temp;
    }

}


bool Controler::playAgain()
{
    if (event.type == SDL_MOUSEBUTTONDOWN)
        return true;
    if (event.type == SDL_KEYDOWN)
        return false;
}

void Controler::Init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, 0);

    //Load Font chữ
    if (TTF_Init() != -1)
    {
        font = TTF_OpenFont("Font/Ubuntu-Medium.ttf", 20);
    }

    // Load ảnh
    Bird.CreateTexture1("Image/yellowbird1.png", renderer);
    Bird.CreateTexture2("Image/yellowbird2.png", renderer);
    Bird.CreateTexture3("Image/yellowbird3.png", renderer);
    Background.CreateTexture("Image/background.png", renderer);
    Mess.CreateTexture("Image/message.png", renderer);
    BU.CreateTexture("Image/pipe_Above.png", renderer);
    BD.CreateTexture("Image/pipe_Below.png", renderer);
    Over.CreateTexture("Image/gameover.png", renderer);
    Score.CreateTexture("Image/Score.png", renderer);
    Point[0].CreateTexture("Image/0.png", renderer);
    Point[1].CreateTexture("Image/1.png", renderer);
    Point[2].CreateTexture("Image/2.png", renderer);
    Point[3].CreateTexture("Image/3.png", renderer);
    Point[4].CreateTexture("Image/4.png", renderer);
    Point[5].CreateTexture("Image/5.png", renderer);
    Point[6].CreateTexture("Image/6.png", renderer);
    Point[7].CreateTexture("Image/7.png", renderer);
    Point[8].CreateTexture("Image/8.png", renderer);
    Point[9].CreateTexture("Image/9.png", renderer);
    BronzeMedal.CreateTexture("Image/BronzeMedal.png", renderer);
    SilverMedal.CreateTexture("Image/SilverMedal.png", renderer);
    GoldMedal.CreateTexture("Image/GoldMedal.png", renderer);
    /*SoundOn.CreateTexture("Image/soundOn.png", renderer);
    SoundOff.CreateTexture("Image/soundOff.png", renderer);*/
}


void Controler::Clear()
{
    if (isOver)
    {
        //while(event.type != SDL_MOUSEBUTTONDOWN)
        //SDL_Delay(1500);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

bool Controler::getContinue()
{
    return Continue;
}

void Controler::MainMenu()
{
   
    Menu.Init(renderer);
    
    while (!Menu.getClicked())
    {
        if (Menu.EventHandling(event, renderer) == -1)
        {
            exit = true;
            break;
        }
        Menu.Render(renderer);
        SoundOn.Render(renderer);
        
    }
    if (Menu.getClicked() == true)
        isClicked = true;
}
bool Controler::exitGame()
{
    return exit;
}

void Controler::Event()
{
    //isOver = false;
    SDL_PollEvent(&event);
    Bird.GetJumpTime();

    if (event.type == SDL_QUIT) exit = true;
    
    if (Bird.getYpos() <= 0 || Bird.getYpos() >= HEIGHT) isOver = true;
    if (isOver)
    {
        Mix_PlayChannel(-1, hit, 0);
        //cout << "HighScore:" << highscore;
        SDL_RenderClear(renderer);
        //Score.Render(renderer);
        SDL_Delay(2000);
        
        Continue = false;
              
    }

    if (event.type == SDL_KEYDOWN || event.type == SDL_MOUSEBUTTONDOWN)
    {
        firstAction = true;
        if (event.key.keysym.sym == SDLK_UP || event.type == SDL_MOUSEBUTTONDOWN)
        {
            Mix_PlayChannel(-1, click, 0);
            if (!Bird.JumpState()) 
                Bird.Jump();
            else if (getFirstAction())
                Bird.Gravity();
        }
        else if (getFirstAction())
            Bird.Gravity();
    }
    else if (getFirstAction())
        Bird.Gravity();
}

// xu li va cham
bool Controler::Check(Node a, Node b)
{
    int x1 = a.x, y1 = a.y,
        u1 = a.x + a.w, v1 = a.y + a.h;

    int x2 = b.x, y2 = b.y,
        u2 = b.x + b.w, v2 = b.y + b.h;

    if (x1 <= x2 && x2 <= u1 && y1 <= y2 && y2 <= v1) return true;

    if (x1 <= u2 && u2 <= u1 && y1 <= y2 && y2 <= v1) return true;

    if (x1 <= x2 && x2 <= u1 && y1 <= v2 && v2 <= v1) return true;

    if (x1 <= u2 && u2 <= u1 && y1 <= v2 && v2 <= v1) return true;

    Node c = a;
    a = b;
    b = c;

    x1 = a.x, y1 = a.y, u1 = a.x + a.w, v1 = a.y + a.h;

    x2 = b.x, y2 = b.y, u2 = b.x + b.w, v2 = b.y + b.h;
    if (x1 <= x2 && x2 <= u1 && y1 <= y2 && y2 <= v1) return true;

    if (x1 <= u2 && u2 <= u1 && y1 <= y2 && y2 <= v1) return true;

    if (x1 <= x2 && x2 <= u1 && y1 <= v2 && v2 <= v1) return true;

    if (x1 <= u2 && u2 <= u1 && y1 <= v2 && v2 <= v1) return true;
    return false;
}

void Controler::Render()
{
    Time++;
    if (!getFirstAction() )
    {
        SDL_RenderClear(renderer);
        Background.Render(renderer);
        Mess.Render(renderer);
        Bird.Render(renderer);
        SDL_RenderPresent(renderer);
    }
    else
    {
        SDL_RenderClear(renderer);
        Background.Render(renderer);

        
        if (score == 0)
        {
            Point[0].setSrc(0, 0, 36, 24);
            Point[0].setDest(0, 0, 36, 24);
            Point[0].Render(renderer);
        }
        
        for (int i = 0;i < MAXN;++i)
        {
            // cot di chuyen
            blockU[i].x -= 2;
            BU.setDest(blockU[i].x, blockU[i].y, blockU[i].h, blockU[i].w);
            blockD[i].x -= 2;
            BD.setDest(blockD[i].x, blockD[i].y, blockD[i].h, blockD[i].w);

            if (blockD[i].x >= -80 && blockD[i].x <= 800)
            {
                Node RECT_BIRD = { Bird.getDest().x,Bird.getDest().y,Bird.getDest().h,Bird.getDest().w };
                printScore();
                BU.Render(renderer), BD.Render(renderer);
                
                if (Check(RECT_BIRD, blockD[i]) || Check(RECT_BIRD, blockU[i]))
                {
                    isOver = true;             
                    
                    //SDL_RenderCopy(renderer, Message, NULL, &Message_rect);              
                   
                }
                else if (RECT_BIRD.x > blockD[i].x + blockD[i].w)
                {
                    
                    int flag = 0;
                    if (i + 1 > score)
                    {
                        score = i + 1;
                        flag = 1;
                    }
                    if (flag == 1)
                        Mix_PlayChannel(-1, point, 0);
                }
            }
        }
        BD.Render(renderer);
        Bird.Render(renderer);
        if (isOver)
        {
            Over.Render(renderer);
            Score.Render(renderer);
            
            ifstream file("HighScore.txt");
            file >> highscore;
            file.close();
            if (score > highscore)
            {
                highscore = score;
                ofstream file("HighScore.txt");
                file << score;
                file.close();
            }

            stringstream score_string;
            score_string << score;
            string temp_score_str = score_string.str();
            char* score_text = (char*)temp_score_str.c_str();
            surfaceMessage = TTF_RenderText_Solid(font, score_text, color);
            Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
            int countScoreNumber = 0;
            if (score >= 100)
            {
                countScoreNumber = 3;
                Medal = GoldMedal;
            }
            else if (score >= 10)
            {
                countScoreNumber = 2;
                Medal = SilverMedal;
            }
            else
            {
                countScoreNumber = 1;
                Medal = BronzeMedal;
            }
            Message_rect.x = 575 - 30* countScoreNumber;
            Message_rect.y = 255;
            Message_rect.w = 30* countScoreNumber;
            Message_rect.h = 50;
            SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

            stringstream high_score_string;
            high_score_string << highscore;
            string temp_high_score_str = high_score_string.str();
            char* high_score_text = (char*)temp_high_score_str.c_str();
            surfaceMessage = TTF_RenderText_Solid(font, high_score_text, color);
            Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
            int countHighScoreNumber = 0;
            if (highscore >= 100) countHighScoreNumber = 3;
            else if (highscore >= 10) countHighScoreNumber = 2;
            else countHighScoreNumber = 1;

            Message_rect.x = 575 - 30 * countHighScoreNumber;
            Message_rect.y = 320;
            Message_rect.w = 30 * countHighScoreNumber;
            Message_rect.h = 50;
            SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
                    
            Medal.Render(renderer);
        }
        SDL_RenderPresent(renderer);        
    }
}
bool Controler::getClicked()
{
    return isClicked;
}

int Controler::reverse(int point)
{
    int k = point;
    int reversePoint = 0;
    while (k > 0)
    {
        reversePoint = reversePoint * 10 + k % 10;
        k = k / 10;
    }
    return reversePoint;
}

void Controler::printScore()
{
    //Setscreen
    
    //xu li neu score % 10 = 0
    j = 0;
    secondScore = score;
    while (secondScore % 10 == 0 && secondScore != 0)
    {
        j++;
        secondScore /= 10;
    }
    while (j > 0)
    {
        Point[0].setDest(0 + j * 30, 0, 36, 24);
        Point[0].Render(renderer);
        j--;
    }

    //print diem so
    score_ = reverse(score);
    while (score_ > 0)
    {
        leftNum = score_ % 10;        
           
        Point[leftNum].setDest(0 + j * 30, 0, 36, 24);
        Point[leftNum].Render(renderer);
        score_ /= 10;
        j++;            
    }    
}
void Controler::setClicked(bool flags)
{
    isClicked = flags;
}

bool Controler::getFirstAction()
{
    return firstAction;
}