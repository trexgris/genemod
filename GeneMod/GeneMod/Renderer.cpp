#include "stdafx.h"
#include "Renderer.h"


Renderer::Renderer(const int screenWidth, const int screenHeight)
	:
	screenWidth(screenWidth),
	screenHeight(screenHeight),
	gBGTexture(this),
	gDotTexture(this)
{
	gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

bool Renderer::LoadMedia()
{
	//Loading success flag
	bool success = true;

	//Load dot texture
	if (!gDotTexture.loadFromFile("dot.bmp"))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}

	//Load background texture
	if (!gBGTexture.loadFromFile("bg.png"))
	{
		printf("Failed to load background texture!\n");
		success = false;
	}

	return success;
}



Renderer::~Renderer()
{
}
