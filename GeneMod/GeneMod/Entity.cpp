#include "stdafx.h"
#include "Entity.h"
//#include "SDL_keyboard.h"
//#include "SDL_keycode.h"
#include "SDL_events.h"
#include "SDL_keyboard.h"
#include "TextureWrapper.h"
#include "Renderer.h"

Entity::Entity(std::shared_ptr<Renderer> renderer)
	:renderer(renderer)
{
	//Initialize the offsets
	mPosX = 0;
	mPosY = 0;

	//Initialize the velocity
	mVelX = 0;
	mVelY = 0;
}

Entity::~Entity()
{}

void Entity::handleEvent(SDL_Event& e)
{
	//If a key was pressed
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: mVelY -= DOT_VEL; break;
		case SDLK_DOWN: mVelY += DOT_VEL; break;
		case SDLK_LEFT: mVelX -= DOT_VEL; break;
		case SDLK_RIGHT: mVelX += DOT_VEL; break;
		}
	}
	//If a key was released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: mVelY += DOT_VEL; break;
		case SDLK_DOWN: mVelY -= DOT_VEL; break;
		case SDLK_LEFT: mVelX += DOT_VEL; break;
		case SDLK_RIGHT: mVelX -= DOT_VEL; break;
		}
	}
}

void Entity::move()
{
	//Move the dot left or right
	mPosX += mVelX;

	if (!renderer)
		bool t = true;
	//If the dot went too far to the left or right
	if ((mPosX < 0) || (mPosX + DOT_WIDTH > renderer->GetScreenWidth()))
	{
		//Move back
		mPosX -= mVelX;
	}

	//Move the dot up or down
	mPosY += mVelY;

	//If the dot went too far up or down
	if ((mPosY < 0) || (mPosY + DOT_HEIGHT > renderer->GetScreenHeight()))
	{
		//Move back
		mPosY -= mVelY;
	}
}

void Entity::render()
{
	if (!texture)
		bool t = true;
	//Show the dot
	renderer->GetDotTexture().render(mPosX, mPosY);
}