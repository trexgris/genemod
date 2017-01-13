#include "stdafx.h"
#include "SDLNetSession.h"
#include "SDL_net.h"
#include <iostream>

SDLNetSession::SDLNetSession()
{
}


SDLNetSession::~SDLNetSession()
{
}

bool SDLNetSession::Init()
{
	if (SDLNet_Init() < 0) {
		std::cerr << "SDLNet_Init: " << SDLNet_GetError() << std::endl;
		return false;
	}
	else
		return true;
}

void SDLNetSession::Close()
{
	SDLNet_Quit();
}