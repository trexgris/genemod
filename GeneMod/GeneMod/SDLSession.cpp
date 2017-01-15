#include "stdafx.h"
#include "SDLSession.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Renderer.h"
#include "SDLSessionClient.h"
#include "SDLSessionHost.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDLSession::SDLSession()
	:
	connected(false),
	sessionClient(nullptr),
	sessionHost(nullptr)
{
	//renderer = std::make_shared<Renderer>(SCREEN_WIDTH, SCREEN_HEIGHT);
}

void SDLSession::InitRenderer()
{
	renderer = std::make_shared<Renderer>(SCREEN_WIDTH, SCREEN_HEIGHT);

}

SDLSession::~SDLSession()
{
}


void SDLSession::Close()
{
	//Free loaded images
	renderer->GetDotTexture().free();
	renderer->GetBgTexture().free();

	//Destroy window	
	SDL_DestroyRenderer(renderer->GetgRenderer());
	SDL_DestroyWindow(renderer->GetgWindow());
//	gWindow = nullptr; // to put in renderer destructor
	//renderer->GetgRende//->GetgRenderer() = nullptr;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}


bool SDLSession::Init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		InitRenderer();

		// = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (renderer->GetgWindow() == nullptr)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			//gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (renderer->GetgRenderer() == nullptr)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(renderer->GetgRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}
	return success;
}


void SDLSession::InitHostSession()
{
	sessionClient.reset(new SDLSessionClient);
	sessionClient->InitConnection();
}
void SDLSession::InitClientSession()
{
	sessionHost.reset(new SDLSessionHost);
	sessionClient->InitConnection();

}