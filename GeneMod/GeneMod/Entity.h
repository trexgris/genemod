#pragma once
#include "SDL.h"
#include <memory>

class TextureWrapper;
class Renderer;

class Entity
{
public:
	Entity(std::shared_ptr<Renderer>);
	//The dimensions of the dot
	static const int DOT_WIDTH = 20;
	static const int DOT_HEIGHT = 20;

	//Maximum axis velocity of the dot
	static const int DOT_VEL = 10;

	//Initializes the variables
	Entity();
	virtual ~Entity();

	//Takes key presses and adjusts the dot's velocity
	void handleEvent(SDL_Event& e);

	//Moves the dot
	void move();

	//Shows the dot on the screen
	void render();

private:
	TextureWrapper * texture;
	std::shared_ptr<Renderer> renderer;

	//The X and Y offsets of the dot
	int mPosX, mPosY;

	//The velocity of the dot
	int mVelX, mVelY;
};

