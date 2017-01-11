#pragma once
#include "TextureWrapper.h"

class Renderer
{
public:
	Renderer(const int, const int);
	~Renderer();
	const int GetScreenWidth() const { return screenWidth; };
	const int GetScreenHeight() const { return screenHeight; };

	TextureWrapper& GetBgTexture() {
		return gBGTexture;	};

	TextureWrapper& GetDotTexture() {
		return gBGTexture;
	};
	SDL_Window* GetgWindow() { return gWindow; }
	SDL_Renderer * GetgRenderer() { return gRenderer; }

	bool LoadMedia();

private:
	const int screenWidth, screenHeight;

	//need to be moved to an entity manager class
	TextureWrapper gDotTexture, gBGTexture;

	//The window we'll be rendering to
	SDL_Window* gWindow;

	//The window renderer
	SDL_Renderer* gRenderer;
};

