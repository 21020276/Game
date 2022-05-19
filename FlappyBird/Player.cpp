#include "Player.h"
#include "Control.h"
#include<iostream>

void Player::Render(SDL_Renderer* ren)
{
	animationTimer++;
	SDL_Rect pSRC = getSrc();
	SDL_Rect pDest = getDest();
	if (animationTimer < 10)
	{
		SDL_RenderCopyEx(ren, Tex1, &pSRC, &pDest, 0, NULL, SDL_FLIP_NONE);
	}
	else if (animationTimer >= 10 && animationTimer <= 20)
	{
		SDL_RenderCopyEx(ren, Tex2, &pSRC, &pDest, 0, NULL, SDL_FLIP_NONE);
	}
	else if (animationTimer > 20)
	{
		SDL_RenderCopyEx(ren, Tex3, &pSRC, &pDest, 0, NULL, SDL_FLIP_NONE);
	}
	if (animationTimer > 30) animationTimer = 0;

}

int Player::getYpos()
{
	return Ypos;
}

void Player::Gravity()
{
	if (JumpState())
	{
		accelerator1 = accelerator1 + 0.035;
		accelerator2 = accelerator2 + 0.035;
		jumpHeight = jumpHeight + gravity;
		Ypos = Ypos + gravity + accelerator1 + accelerator2 + jumpHeight;
		setDest(200, Ypos, 28, 38);
		if (jumpHeight > 0)
		{
			inJump = false;
			jumpHeight = -6; // độ nhảy cao
		}
	}
	else
	{
		accelerator1 = accelerator1 + 0.035;
		accelerator2 = accelerator2 + 0.035;
		Ypos = Ypos + gravity + accelerator1 + accelerator2;
		setDest(200, Ypos, 28, 36);
	}

}

void Player::Jump()
{
	if (jumpTimer - lastJump > 50)
	{
		accelerator1 = 0;
		accelerator2 = 0;
		inJump = true;
		lastJump = jumpTimer;
	}
	else
	{
		Gravity();
	}
}

void Player::GetJumpTime()
{
	jumpTimer = SDL_GetTicks();
}

bool Player::JumpState()
{
	return inJump;
}

void Player::Reset()
{
	accelerator1 = 0;
	accelerator2 = 0;
	Ypos = 256;
	lastJump = 0;
}

void Player::CreateTexture1(const char* address, SDL_Renderer* ren)
{
	Tex1 = TextureManager::Texture(address, ren);
}

void Player::CreateTexture2(const char* address, SDL_Renderer* ren)
{
	Tex2 = TextureManager::Texture(address, ren);
}

void Player::CreateTexture3(const char* address, SDL_Renderer* ren)
{
	Tex3 = TextureManager::Texture(address, ren);
}