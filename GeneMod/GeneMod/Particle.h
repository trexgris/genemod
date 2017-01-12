#pragma once
class TextureWrapper;
class Particle
{
public:
public:
	//Initialize position and animation
	Particle(int x, int y);

	//Shows the particle
	void render();

	//Checks if particle is dead
	bool isDead();
	~Particle();

private:
	//Offsets
	int mPosX, mPosY;

	//Current frame of animation
	int mFrame;

	//Type of particle
	
	TextureWrapper *mTexture;
};

