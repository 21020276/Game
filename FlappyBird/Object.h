#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>
#include"TextureManager.h"

class Object
{
private:
	SDL_Rect src, dest;
	SDL_Texture* Tex;
public:

	SDL_Texture* getTexture();
	SDL_Rect getSrc();
	SDL_Rect getDest();
	void setSrc(int x, int y, int h, int w);
	void setDest(int x, int y, int h, int w);
	void CreateTexture(const char* path, SDL_Renderer* ren);
	void Render(SDL_Renderer* ren);
};